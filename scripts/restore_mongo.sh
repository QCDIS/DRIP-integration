#!/bin/bash


backup_folder=/mnt/data/backup
day=`date '+%d'`
month=`date '+%m'`
year=`date '+%Y'`

mkdir $backup_folder/drip_db
tar -xzvf $backup_folder/DRIP_DB-$year-$month-$day.tar.gz -C $backup_folder/drip_db
docker cp $backup_folder/drip_db dockerfiles_mongo_1:/tmp/drip_db
docker exec -it dockerfiles_mongo_1 sh -c "mongorestore --db drip --drop /tmp/drip_db"
docker exec -it dockerfiles_mongo_1 sh -c "rm -r /tmp/drip_db"