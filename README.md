# About DRIP 

The Dynamic Real-time infrastructure planner (DRIP) allows application developers to seamlessly plan a customized virtual infrastructure based on application level constraints on QoS and resource budgets, provisioning the virtual infrastructure using standardized interfaces (e.g., TOSCA and OCCI), deploy application components onto the virtual infrastructure, and start execution on demand.
 
DRIP is developed by the research team for Quality Critical Applications on Programmable Infrastructure (QCAPI) in the [System and Network Engineering Research Group (SNE)](https://ivi.fnwi.uva.nl/sne/) of the University of Amsterdam. The development of DRIP is coordinated by Dr. Zhiming Zhao. Core developers include Junchao Wang, Huan Zhou, Yang Hu, Paul Martin, Arie Taal and Spiros Koulouzis.
 
The DRIP components are made available as open source under the Apache 2.0 license; the software has been containerized and can be provisioned and deployed on federated virtual infrastructures. The development of DRIP is supported by the European Union Horizon 2020 research and innovation program under grant agreements No. 643963 ([SWITCH](http://www.switchproject.eu/)).

# Architecture and key components

The DRIP system contains a number of micro services (agents):


DRIP has a number of key components:

1. The infrastructure planner (planning agent) will use an adapted partial critical path algorithm to produce efficient infrastructure topologies based on application workflows specified in YAML in compliance with the TOSCA specification.
2. The infrastructure provisioner (provisioning agent) takes the infrastructure plans produced by the planner using TOSCA as input, and directs the provisioning of virtual infrastructure onto underlying infrastructure services. It uses OCCI as default provisioning interface, and currently has been tested on ExoGENI, EC2 and EGI FedCloud.
3. The deployment agent installs application components onto provisioned infrastructure.

# Support

The DRIP system is developed using the Apache license version 2.0. It is open source, and there is no warrant on the software quality. We welcome any suggestions on software features, use-cases and joint research activities. Please contact us via email: z.zhao@uva.nl.


# Deploy

Download the Docker file from [here](https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/valpha/Dockerfile)

***

Build the container: 
```
sudo docker build -t drip .
```

***

Run the container: 
```
sudo docker run --name drip-inst -d drip
```
More information on running Docker images can be found [here](https://docs.docker.com/engine/reference/run/) 
***
To get the IP of the drip-inst container you can run:
```
sudo docker inspect drip-inst
``` 
and look for the filed "IPAddress" 

#Usage Example 

Get the drip client from [here](https://raw.githubusercontent.com/QCAPI-DRIP/DRIP-integradation/master/scripts/drip_client.sh) 

***

Register a new account:
```
./drip_client.sh -l 172.17.0.2 -o register -u test -p 123
```
The output should be something like: 
```
Success: User test is registered!MT
```
***

Get a sample components description file from [here](https://raw.githubusercontent.com/QCAPI-DRIP/DRIP-integradation/master/etc/input.yaml) and submit it to for planning: 
```
./drip_client.sh -l 172.17.0.2 -o plan -u test -p 123 -c input.yaml
```
The output should be something like: 
```XML
<?xml version="1.0" encoding="UTF-8"?>
<result><status/><info/><file name="planner_output_all.yml" level="0">topologies:\n  - topology: 4d1eb4f6-fb17-48e8-8670-a753f0ffd8fd\n    cloudProvider: EC2\n</file><file name="4d1eb4f6-fb17-48e8-8670-a753f0ffd8fd.yml" level="1">publicKeyPath: /Users/zh9314/SWITCH/users/zh9314/files/1479928399024/id_dsa.pub\nuserName: zh9314\nsubnets:\n  - name: s1\n    subnet: 192.168.10.0\n    netmask: 255.255.255.0\ncomponents:\n  - name: 23852656-a19e-4e73-9a27-3a5f512a9242\n    type: Switch.nodes.Compute\n    nodetype: t2.medium\n    OStype: "Ubuntu 16.04"\n    domain: "ec2.us-east-1.amazonaws.com"\n    script: null\n    installation: null\n    role: master\n    dockers: "mogswitch/InputDistributor"\n    public_address: 23852656-a19e-4e73-9a27-3a5f512a9242\n    ethernet_port: \n      - name: p1\n        subnet_name: s1\n        address: 192.168.10.10 \n  - name: 4e64d56c-1d83-4c57-9471-e81b03fd5317\n    type: Switch.nodes.Compute\n    nodetype: t2.medium\n    OStype: "Ubuntu 16.04"\n    domain: "ec2.us-east-1.amazonaws.com"\n    script: null\n    installation: null\n    role: slave\n    dockers: "mogswitch/ProxyTranscoder"\n    public_address: 4e64d56c-1d83-4c57-9471-e81b03fd5317\n    ethernet_port: \n      - name: p1\n        subnet_name: s1\n        address: 192.168.10.11 \n</file></result>
```
At the same time files `plan.xml` and `planning_result.xml` should be generated
***

Upload the plan: 
```
./drip_client.sh -l 172.17.0.2 -o upload -u test -p 123
```
This should generate files `upload.xml` and `actionNumber`

***
Assuming you have an Amazon Cloud account and the corresponding key, key id and certificates set the configuration: 
```
./drip_client.sh -l 172.17.0.2 -o configureEC2 -u test -p 123 -i AKAKAKAKAKAKAK -k o99ifo99ifo99ifo99ifo99ifo99if -d Virginia.pem,California.pem
```
Note: The certificates Virginia.pem and California.pem must be separated by commas without spaces
***

Optional. If you wish to log in to the VMs generated you need to upload your public key (preferably rsa). Instructions on how to generate these keys can be found [here](https://help.ubuntu.com/community/SSH/OpenSSH/Keys)
```
./drip_client.sh -l 172.17.0.2 -o confUserKey -u test -p 123 -s ~/.ssh/id_rsa.pub 
```
***

Optional. If you wish to run a predefined script on the VMs, you should upload it by using: 
```
./drip_client.sh -l 172.17.0.2 -o confscript -u test -p 123 -r sample.sh 
```
***
Execute provisioning: 
```
./drip_client.sh -l 172.17.0.2 -o execute -u test -p 123 
```

***
Finally deploy a kubernetes cluster: 
```
./drip_client.sh -l 172.17.0.2 -o deploy -u test -p 123 
```

# DRIP Client
The DRIP client is a script for building the right requests invoking the DRIP services. 

## Usage:
    
    ./drip_client.sh [OPTION]
    -l , --location HOST                                      The DRIP service IP or hostname
    -o , --operation OPERATION                                The operation for the service to run.
    -u , --username USERNAME                                  DRIP username
    -p , --password USERNAME                                  DRIP password
    -c , --component-description COMPONENT_DESCRIPTION_FILE   The component description yaml file
    -k , --key EC2_KEY                                        The EC2 key
    -i , --key-id EC2_KEY_ID                                  The EC2 key id
    -s , --ssh-key RSA_PUB                                    The user's rsa public key file (id_rsa.pub)
    -r , --script SCRIPT                                      The script to be executed by the VM's
    -d , --cloud-certificates CLOUD_CERTIFICATES              The PEM certificates to use. The files must be separated with commas and no spaces
     
    
##Operations (-o, --operation): 

`register`  Registers a user account. 
Example:                                                
```
./drip_client.sh -l 172.17.0.2 -o register -u test -p 123
```

`plan`  Executes planning for specified components description files. Returns the plan in a file named: `planning_result.xml` 
Example:                                                
```
./drip_client.sh -l 172.17.0.2 -o plan -u test -p 123 -c input.yaml
```

`upload`  Uploads the infrastructure description files (TOSCA). Must run plan before needs action number
Example:                                                 
```
./drip_client.sh -l 172.17.0.2 -o upload -u test -p 123
```

 `configureEC2`  Configure the cloud infrastructure to set domain keys 
Example:                                                
```
./drip_client.sh -l 172.17.0.2 -o configureEC2 -u test -p 123 -i AKAKAKAKAKAKAK -k o99ifo99ifo99ifo99ifo99ifo99if -d Virginia.pem,California.pem
```
   
`confUserKey`  Uploads the public key which the user want to use to access all his instances. (Optional)
Example:                                                
```
./drip_client.sh -l 172.17.0.2 -o confUserKey -u test -p 123 -s ~/.ssh/id_rsa.pub 
```
   
`confscript`  Uploads the script that the user wants to use. (Optional). Must run plan before needs action number.
Example:                                                
```
./drip_client.sh -l 172.17.0.2 -o confscript -u test -p 123 -r sample.sh 
```
   
`execute`  Executes provisioning. Must run plan before needs action number.
Example:                                                
```
./drip_client.sh -l 172.17.0.2 -o execute -u test -p 123 
```

`deploy` Deploy a kubernetes cluster.
Example:                                                
```
./drip_client.sh -l 172.17.0.2 -o deploy -u test -p 123 
```
