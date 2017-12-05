#!/bin/bash

source $1

function runFilter(){
    PROVISION_ID=$1
    CONFIGURATION_ID=$2
    
    DEPLOY_ID=`curl -k -u $USER_USERNAME:$USER_PASSWORD -H "Content-type: application/json" -X POST -d "{\"provisionID\":\"$PROVISION_ID\",\"managerType\":\"ansible\",\"configurationID\":\"$CONFIGURATION_ID\"}" $HOST/drip-api/user/v1.0/deployer/deploy`
}


function printResult(){
    DEPLOY_ID=$1
    declare -A ANSIBLE_OUT
    
    while IFS="=" read -r key value; do ANSIBLE_OUT[$key]="$value"; done < <(curl -k -u $USER_USERNAME:$USER_PASSWORD -X GET $HOST/drip-api/user/v1.0/deployer/$DEPLOY_ID | jq .ansibleOutputList | jq -r "to_entries|map(\"\(.key)=\(.value)\")|.[]")
    for key in "${!ANSIBLE_OUT[@]}"; do  curl -k -u $USER_USERNAME:$USER_PASSWORD $HOST/drip-api/user/v1.0/deployer/ansible/${ANSIBLE_OUT[$key]} 2>/dev/null | jq .result; done
}


if [ ! -f index_file ]; then
    echo "index=\"0\"" > index_file
fi
source index_file
# echo "${PROV_IDS[$index]}"

runFilter ${PROV_IDS[$index]} $CONFIGURATION_ID
echo $DEPLOY_ID
printResult $DEPLOY_ID

((index++))
if [ "$index" -ge "${#PROV_IDS[*]}" ]; then
    index="0"
fi
echo "index=\"$index\"" > index_file



