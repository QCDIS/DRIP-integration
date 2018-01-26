HOST=https://drip.vlan400.uvalight.net:8443
USER_USERNAME=mog_switch
USER_PASSWORD=switch_mog
PLAN_ID=5a3b9a57e4b0286f61fac30b
PLAN_ID=5a5dd928e4b040980c7a9827
PROVISION_ID=5a5e0dafe4b00ad49513dbec
KEY_ID=`curl --connect-timeout 2 --retry 5 -k -u $USER_USERNAME:$USER_PASSWORD $HOST/drip-api/user/v1.0/provisioner/$PROVISION_ID | jq -r .deployerKeyPairIDs[0]`
curl --connect-timeout 2 --retry 5 -k -u $USER_USERNAME:$USER_PASSWORD $HOST/drip-api/user/v1.0/keys/$KEY_ID | jq -r .privateKey.key > id_rsa
chmod 700 id_rsa
MASTER_IP=`curl --connect-timeout 2 --retry 5 -k -u $USER_USERNAME:$USER_PASSWORD $HOST/drip-api/user/v1.0/provisioner/$PROVISION_ID | jq -r .deployParameters | jq '.[] | select(.role=="master")' | jq -r .ip`
USERNAME=`curl --connect-timeout 2 --retry 5 -k -u $USER_USERNAME:$USER_PASSWORD $HOST/drip-api/user/v1.0/provisioner/$PROVISION_ID | jq -r .deployParameters | jq '.[] | select(.role=="master")' | jq -r .user`
echo 'sudo docker service '$1' $(sudo docker stack ls --format "{{.Name}}")_'$2''
ssh $USERNAME@$MASTER_IP -i id_rsa 'sudo docker service '$1' $(sudo docker stack ls --format "{{.Name}}")_'$2''
