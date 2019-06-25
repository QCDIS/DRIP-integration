#!/bin/bash

cd Dockerfiles/deployer
docker build -t drip-deployer .


cd ../manager
docker build -t drip-manager .


cd ../parser
docker build -t drip-parser .

cd ../planner
docker build -t drip-planner .


cd ../provisioner
docker build -t drip-provisioner .
