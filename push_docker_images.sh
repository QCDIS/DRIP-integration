#!/bin/bash

cd Dockerfiles/deployer
docker build -t drip-deployer .
docker tag drip-deployer alogo53/drip-deployer:$1

cd ../manager
docker build -t drip-manager .
docker tag drip-manager alogo53/drip-manager:$1

cd ../parser
docker build -t drip-parser .
docker tag drip-parser alogo53/drip-parser:$1

cd ../planner
docker build -t drip-planner .
docker tag drip-planner alogo53/drip-planner:$1

cd ../provisioner
docker build -t drip-provisioner .
docker tag drip-provisioner alogo53/drip-provisioner:$1
