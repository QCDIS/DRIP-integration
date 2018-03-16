#!/bin/bash


PROXY_FILE=$1
cat $PROXY_FILE |  sed ':a;N;$!ba;s/\n/\\n/g' > tmp_proxy
PROXY=`cat tmp_proxy`
CLOUD_PROVIDER=egi

echo "{\"secretKey\": \"$PROXY\",\"accessKeyId\": \"$MY_PROXY_USERNAME\",\"cloudProviderName\":\"$CLOUD_PROVIDER\"}"
