#!/bin/bash


backup_folder=/mnt/data/backup
catalina_home=/root/apache-tomcat-7.0.75


day=`date '+%d'`
month=`date '+%m'`
year=`date '+%Y'`


# Manager logs 
sudo docker cp dockerfiles_drip-manager_1:$catalina_home/logs $backup_folder
cd $backup_folder/logs
sudo tar -zcvf DRIP_logs-$month-$year.tar.gz *.$year-$month-*.*
sudo mv DRIP_logs-10-2017.tar.gz $backup_folder
sudo rm $backup_folder/logs/*.$year-$month-*.*
sudo docker exec -it dockerfiles_drip-manager_1 sh -c "rm $catalina_home/logs/*.$year-$month-*.*"



# Mogno
sudo docker exec -it dockerfiles_mongo_1 sh -c "mongodump -v --host localhost:27017 --out=/tmp"
sudo docker cp dockerfiles_mongo_1:/tmp/drip $backup_folder
cd $backup_folder/drip
sudo tar -zcvf $backup_folder/DRIP_DB-$month-$year.tar.gz *.*
sudo rm  $backup_folder/drip/*
sudo docker exec -it dockerfiles_mongo_1 sh -c "rm -r /tmp/drip"