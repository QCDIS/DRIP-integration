#!/bin/bash

function checkSucces {
    success=$1
    if [ -z "$success" ]
    then
        echo "$2 Faild: "$success
        exit -1
    fi

}


function register {
    echo "<register>" > register.xml
    echo "<user>$1</user>" >> register.xml
    echo "<pwd>$2</pwd>" >> register.xml
    echo "</register>" >> register.xml
    
    out=`curl -si -X POST -H "Content-type:text/xml" -d @register.xml http://$REST_SERVER:8080/REST_Provisioner/switch/account/register`
    success=`echo $out | grep "HTTP/1.[01] 20.." 2>&1`
    checkSucces "${success}" "${FUNCNAME}"
    echo $out
}




function plan {
            
    sed ':a;N;$!ba;s/\n/\\n/g' $3 > $3".flat"
    flatPlan=`cat $3".flat"`

    echo "<plan>" > plan.xml
    echo "<user>$1</user>" >> plan.xml
    echo "<pwd>$2</pwd>" >> plan.xml
    echo "<file>$flatPlan</file>" >> plan.xml
    echo "</plan>" >> plan.xml
    
    curl -s  POST -H "Content-type:text/xml" -d @plan.xml http://$REST_SERVER:8080/REST_Provisioner/switch/plan/planning > planning_result.xml
    
    cat planning_result.xml
}


function configureEC2 {
    args=( "$@" )
    usr=${args[0]}
    pwd=${args[1]}
    keyid=${args[2]}
    key=${args[3]}
    
    echo "<configure>" > configure.xml
    echo "<user>$usr</user>" >> configure.xml
    echo "<pwd>$pwd</pwd>" >> configure.xml
    echo "<keyid>$keyid</keyid>" >> configure.xml
    echo "<key>$key</key>" >> configure.xml

    

    for i in "${!args[@]}"
    do
        if [ $i -ge 4 ]
        then
            domain_name=$(basename "${args[$i]}")
            domain_name="${domain_name%.*}"
            inTag="<loginKey domain_name=\"$domain_name\">"           
            sed ':a;N;$!ba;s/\n/\\n/g' ${args[$i]} > $domain_name".flat"
            flatKey=`cat $domain_name".flat"`
            echo $inTag $flatKey "</loginKey>" >> configure.xml
        fi
    done
    echo "</configure>" >> configure.xml
    
    curl -s -X POST -H "Content-type:text/xml" -d @configure.xml http://$REST_SERVER:8080/REST_Provisioner/switch/account/configure/ec2
}



function upload {

    args=( "$@" )
    usr=${args[0]}
    pwd=${args[1]}
    planningRes=${args[2]}
    
    echo "<upload>" > upload.xml
    echo "<user>$usr</user>" >> upload.xml
    echo "<pwd>$pwd</pwd>" >> upload.xml
    xmllint --xpath '//file' $planningRes >> upload.xml
    echo "</upload>" >> upload.xml
    
    actionNumber=`curl -s -X POST -H "Content-type:text/xml" -d @upload.xml http://$REST_SERVER:8080/REST_Provisioner/switch/provision/upload`
    echo $actionNumber | grep -o '[^Action number:  ]\+$' > actionNumber

}

function confUserKey {
    
    args=( "$@" )
    usr=${args[0]}
    pwd=${args[1]}
    actionNumberFile=${args[2]}
    userKeyPath=${args[3]}
    
    echo "<confUserKey>" > confUserKey.xml
    echo "<user>$usr</user>" >> confUserKey.xml
    echo "<pwd>$pwd</pwd>" >> confUserKey.xml
    keyFileName=$(basename "$userKeyPath")
    echo "<userKey name=\"$keyFileName\">"  >> confUserKey.xml
    sed ':a;N;$!ba;s/\n/\\n/g' $userKeyPath >> confUserKey.xml
    echo "</userKey>" >> confUserKey.xml
    action=`cat $actionNumberFile`
    echo "<action>$action</action>" >> confUserKey.xml
    echo "</confUserKey>" >> confUserKey.xml
    
    curl -v -X POST -H "Content-type:text/xml" -d @confUserKey.xml http://$REST_SERVER:8080/REST_Provisioner/switch/provision/confuserkey
}



function confscript {
    
    args=( "$@" )
    usr=${args[0]}
    pwd=${args[1]}
    actionNumberFile=${args[2]}
    scriptPath=${args[3]}
    
    echo "<confScript>" > confScript.xml
    echo "<user>$usr</user>" >> confScript.xml
    echo "<pwd>$pwd</pwd>" >> confScript.xml
    sed ':a;N;$!ba;s/\n/\\n/g' $scriptPath > $scriptPath".flat"
    flat=`cat $scriptPath.flat`
    echo "<script><![CDATA["$flat"]]></script>" >> confScript.xml
    action=`cat $actionNumberFile`
    echo "<action>$action</action>" >> confScript.xml
    echo "</confScript>" >> confScript.xml
    
    curl -v -X POST -H "Content-type:text/xml" -d @confScript.xml http://$REST_SERVER:8080/REST_Provisioner/switch/provision/confscript
}


function execute {

    args=( "$@" )
    usr=${args[0]}
    pwd=${args[1]}
    actionNumberFile=${args[2]}
    
    echo "<execute>" > execute.xml
    echo "<user>$usr</user>" >> execute.xml
    echo "<pwd>$pwd</pwd>" >> execute.xml
    action=`cat $actionNumberFile`
    echo "<action>$action</action>" >> execute.xml
    echo "</execute>" >> execute.xml

    curl -s -X POST -H "Content-type:text/xml" -d @execute.xml http://$REST_SERVER:8080/REST_Provisioner/switch/provision/execute > execute_result.xml
    cat execute_result.xml
}



function deploy {

    args=( "$@" )
    usr=${args[0]}
    pwd=${args[1]}
    actionNumberFile=${args[2]}
    
    echo "<deploy>" > deploy.xml
    echo "<user>$usr</user>" >> deploy.xml
    echo "<pwd>$pwd</pwd>" >> deploy.xml
    action=`cat $actionNumberFile`
    echo "<action>$action</action>" >> deploy.xml
    echo "</deploy>" >> deploy.xml
    
    curl -s -X POST -H "Content-type:text/xml" -d @deploy.xml http://$REST_SERVER:8080/REST_Provisioner/switch/deploy/kubernetes > deploy_result.xml
    cat deploy_result.xml
}


function usage()
{
    
    echo "Usage:"
    echo ""
    echo "./drip_client.sh [OPTION]"
    echo "-l , --location HOST                                      The DRIP service IP or hostname"
    echo "-o , --operation OPERATION                                The operation for the service to run."
    echo "-u , --username USERNAME                                  DRIP username"
    echo "-p , --password USERNAME                                  DRIP password"
    echo "-c , --component-description COMPONENT_DESCRIPTION_FILE   The component description yaml file"
    echo "-k , --key EC2_KEY                                        The EC2 key"
    echo "-i , --key-id EC2_KEY_ID                                  The EC2 key id"
    echo "-s , --ssh-key RSA_PUB                                    The user's rsa public key file (id_rsa.pub)"
    echo "-r , --script SCRIPT                                      The script to be executed by the VM's"
#     echo "-a , --action ACTION_NUMBER_FILE                          The file containing the action number"
    echo "-d , --cloud-certificates CLOUD_CERTIFICATES              The PEM certificates to use. The files must be separated with commas and no spaces"
     
    
    echo "Operations: "
    
    echo "register                                                  Register a user account."
    echo "  Example:                                                ./drip_client.sh -l 172.17.0.2 -o register -u test -p 123"
    echo
    echo "plan                                                      Execute planning for specified components description files. Returns the plan in a file named: planning_result.xml"
    echo "  Example:                                                ./drip_client.sh -l 172.17.0.2 -o plan -u test -p 123 -c input.yaml"
    echo
    echo "upload                                                    Upload the infrastructure description files (TOSCA). Must run plan before needs action number"
    echo "  Example:                                                 ./drip_client.sh -l 172.17.0.2 -o upload -u test -p 123"
    echo domain
    echo "configureEC2                                              Configure the cloud infrastructure to set doman keys "
    echo "  Example:                                                ./drip_client.sh -l 172.17.0.2 -o configureEC2 -u test -p 123 -i AKAKAKAKAKAKAK -k o99ifo99ifo99ifo99ifo99ifo99if -d Virginia.pem,California.pem"
    echo
    echo "confUserKey                                               Upload the public key which the user want to use to access all his instances. (Optional)"
    echo "  Example:                                                ./drip_client.sh -l 172.17.0.2 -o confUserKey -u test -p 123 -s ~/.ssh/id_rsa.pub "
    echo
    echo "confscript                                                Upload the script that the user wants to use. (Optional). Must run plan before needs action number."
    echo "  Example:                                                ./drip_client.sh -l 172.17.0.2 -o confscript -u test -p 123 -r sample.sh "
    echo
    echo "execute                                                   Execute provisioning. Must run plan before needs action number."
    echo "  Example:                                                ./drip_client.sh -l 172.17.0.2 -o execute -u test -p 123 "
    echo
    echo "deploy                                                    Deploy a kubernetes cluster."
    echo "  Example:                                                ./drip_client.sh -l 172.17.0.2 -o deploy -u test -p 123 "
}


if [ "$1" == "" ]
then
    usage
    exit 1
fi

# Code based on http://stackoverflow.com/questions/192249/how-do-i-parse-command-line-arguments-in-bash
while [[ $# -gt 1 ]]
do
key="$1"

case $key in

    -l|--location)
    REST_SERVER="$2"
    shift # past argument
    ;;
    -o|--operation)
    OPERATION="$2"
    shift # past argument
    ;;
    -u|--username)
    DRIP_UNAME="$2"
    shift # past argument
    ;;
    -p|--password)
    DRIP_PWD="$2"
    shift # past argument
    ;;
    -c|--component-description)
    COMPONENT_DESCRIPTION="$2"
    shift # past argument
    ;;
    -k|--key)
    KEY="$2"
    shift # past argument
    ;;
    -i|--key-id)
    KEY_ID="$2"
    shift # past argument
    ;;
    -s|--ssh-key)
    SSH_KEY="$2"
    shift # past argument
    ;;
    -r|--script)
    SCRIPT="$2"
    shift # past argument
    ;;
    -a|--action)
    ACTION_NUMBER="$2"
    shift # past argument
    ;;
    -d|--cloud-certificates)
    CLOUD_CERTS="$2"
    shift # past argument
    ;;
    -h|--help)
    usage
    exit
    ;;
    *)
            
    ;;
esac
shift # past argument or value
done


case ${OPERATION} in
plan)
  plan $DRIP_UNAME $DRIP_PWD $COMPONENT_DESCRIPTION
  ;;
configureEC2)
  certs=`echo $CLOUD_CERTS | sed 's/,/ /g'`
  configureEC2 $DRIP_UNAME $DRIP_PWD $KEY_ID $KEY $certs #"Virginia.pem" "CaliforniaCopy.pem"
  ;;
upload)
  upload $DRIP_UNAME $DRIP_PWD "planning_result.xml"
  ;;
register)
  register $DRIP_UNAME $DRIP_PWD
  ;;
confUserKey)
  confUserKey $DRIP_UNAME $DRIP_PWD "actionNumber" $SSH_KEY #"$HOME/.ssh/id_rsa.pub"
  ;;
confscript)
  confscript $DRIP_UNAME $DRIP_PWD "actionNumber" $SCRIPT
  ;;
execute)
  execute $DRIP_UNAME $DRIP_PWD "actionNumber"
  ;;
deploy)
  deploy  $DRIP_UNAME $DRIP_PWD "actionNumber"
  ;;
*)
  usage
  ;;
esac
