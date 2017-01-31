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

# Usage Example 

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
     
    
## Operations (-o, --operation): 

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

# DRIP REST API
## Planner REST API
Operation: Execute planning for specified components description files.
```
http://$REST_SERVER:8080/REST_Provisioner/switch/plan/planning
```
Input parameter (XML String):

```XML
<plan>
    <user>test</user>
    <pwd>1234</pwd>
    <file>tosca_definitions\n</file>
</plan>
```
The `<file>` node contains a YAML component description. In this element all new lines have to be represented with the '\n' character. This can be done with sed:
```
 sed ':a;N;$!ba;s/\n/\\n/g'
```

Example: 
```XML
<plan>
    <user>test</user>
    <pwd>123</pwd>
    <file>tosca_definitions_version: tosca_simple_yaml_1_0\n\n\ndescription: example file for infrastructure planner\n\n\nrepositories:\n    MOG_docker_hub: \n      description: MOG project’s code repository in GitHub\n      url: https://github.com/switch-project/mog\n      credential:\n        protocol: xauth\n        token_type: X-Auth-Token\n        # token encoded in Base64\n        token: 604bbe45ac7143a79e14f3158df67091\n\n\nartifact_types:\n  tosca.artifacts.Deployment.Image.Container.Docker:\n    derived_from: tosca.artifacts.Deployment.Image\n\n\ndata_types:\n  Switch.datatypes.QoS.AppComponent:\n    derived_from: tosca.datatypes.Root\n    properties:\n      response_time:\n        type: string\n\n  Switch.datatypes.Application.Connection.EndPoint:\n    derived_from: tosca.datatypes.Root\n    properties:\n      address:\n        type: string\n      component_name:\n        type: string\n      netmask:\n        type: string\n      port_name:\n        type: string\n\n  Switch.datatypes.Application.Connection.Multicast:\n    derived_from: tosca.datatypes.Root\n    properties:\n      multicastAddrIP:\n        type: string\n      multicastAddrPort:\n        type: integer\n\n  Switch.datatypes.Network.EndPoint:\n    derived_from: tosca.datatypes.Root\n    properties:\n      address:\n        type: string\n      host_name:\n        type: string\n      netmask:\n        type: string\n      port_name:\n        type: string\n\n  Switch.datatypes.Network.Multicast:\n    derived_from: tosca.datatypes.Root\n    properties:\n      multicastAddrIP:\n        type: string\n      multicastAddrPort:\n        type: integer\n\n\nnode_types:\n\n  Switch.nodes.Application.Container.Docker:\n    derived_from: tosca.nodes.Container.Application\n    properties:\n      QoS:\n        type: Switch.datatypes.QoS.AppComponent\n    artifacts:\n      docker_image:\n        type: tosca.artifacts.Deployment.Image.Container.Docker\n    interfaces:\n      Standard:\n        create:\n          inputs:\n            command:\n              type: string\n            exported_ports:\n              type: list\n              entry_schema:\n                type: string\n            port_bindings:\n              type: list\n              entry_schema:\n                type: string\n\n  Switch.nodes.Application.Container.Docker.MOG.InputDistributor:\n    derived_from: Switch.nodes.Application.Container.Docker\n    artifacts:\n      docker_image:\n        type: tosca.artifacts.Deployment.Image.Container.Docker\n        file: "mogswitch/InputDistributor:1.0"\n        repository: MOG_docker_hub\n    properties:\n      inPort: \n        type: integer\n      waitingTime:\n        type: integer\n      multicastAddrIP:\n        type: string\n      multicastAddrPort:\n        type: integer\n      videoWidth:\n        type: integer\n      videoHeight:\n        type: integer\n\n  Switch.nodes.Application.Container.Docker.MOG.ProxyTranscoder:\n    derived_from: Switch.nodes.Application.Container.Docker \n    artifacts:\n      docker_image:\n        type: tosca.artifacts.Deployment.Image.Container.Docker\n        file: "mogswitch/ProxyTranscoder:1.0"\n        repository: MOG_docker_hub\n    properties:\n      multicastAddrIP: \n        type: string\n      multicastAddrPort:\n        type: integer\n      videoWidth:\n        type: integer\n      videoHeight:\n        type: integer\n\n  Switch.nodes.Application.Connection:\n    derived_from: tosca.nodes.Root \n    properties:\n      source:\n        type: Switch.datatypes.Application.Connection.EndPoint\n      target:\n        type: Switch.datatypes.Application.Connection.EndPoint\n      bandwidth:\n        type: string\n      latency: \n        type: string\n      jitter:  \n        type: string\n      multicast:\n        type: Switch.datatypes.Application.Connection.Multicast\n\n  Switch.nodes.Compute:\n    derived_from: tosca.nodes.Compute\n    properties:\n      OStype:\n        type: string\n      nodetype:\n        type: string\n      domain:\n        type: string\n      public_address:\n        type: string\n      
        ethernet_port:\n        type: list\n        entry_schema:\n          type: tosca.datatypes.network.NetworkInfo\n      script:\n        type: string\n      installation:\n        type: string\n      ssh_credential:\n        type: tosca.datatypes.Credential\n\n  Switch.nodes.Network:\n    derived_from: tosca.nodes.network.Network\n    properties:\n      bandwidth:\n        type: string\n      latency:\n        type: string\n      jitter:\n        type: string\n      source:\n        type: Switch.datatypes.Network.EndPoint\n      target:\n        type: Switch.datatypes.Network.EndPoint\n      multicast:\n        type: Switch.datatypes.Network.Multicast\n\n\ntopology_template:\n  \n  node_templates:\n    2d13d708e3a9441ab8336ce874e08dd1:\n      type: Switch.nodes.Application.Container.Docker.MOG.InputDistributor\n      artifacts:\n        docker_image:\n          file: "mogswitch/InputDistributor:1.0"\n          type: tosca.artifacts.Deployment.Image.Container.Docker\n          repository: MOG_docker_hub\n      properties:\n        QoS:\n          response_time: 30ms\n        inPort: 2000\n        waitingTime: 5\n        multicastAddrIP: 255.2.2.0\n        multicastAddrPort: 3000\n        videoWidth: 176\n        videoHeight: 100\n      interfaces:\n        Standard:\n          create:\n            implementation: docker_image\n            inputs:\n              command: InputDistributor\n              exported_ports:\n                - 2000\n              port_bindings:\n                - "2000:2000"\n                - "3000:3000"\n\n    8fcc1788d9ee462c826572c79fdb2a6a:\n      type: Switch.nodes.Application.Container.Docker.MOG.ProxyTranscoder\n      artifacts:\n        docker_image:\n          file: "mogswitch/ProxyTranscoder:1.0"\n          type: tosca.artifacts.Deployment.Image.Container.Docker\n          repository: MOG_docker_hub\n      properties:\n        QoS:\n          response_time: 30ms\n        multicastAddrIP: 255.2.2.0\n        multicastAddrPort: 3000\n        videoWidth: 176\n        videoHeight: 100\n      interfaces:\n        Standard:\n          create:\n            implementation: docker_image\n            inputs:\n              command: ProxyTranscoder\n              exported_ports:\n                - 80\n              port_bindings:\n                - "8080:80"\n\n    5e0add703c8a43938a39301f572e46c0:\n      type: Switch.nodes.Application.Connection\n      properties:\n        source:\n          address: 192.168.21.11\n          component_name: 2d13d708e3a9441ab8336ce874e08dd1\n          netmask: 255.255.255.0\n          port_name: "inputDistributor_out"\n        target:\n          address: 192.168.21.12\n          component_name: 8fcc1788d9ee462c826572c79fdb2a6a\n          netmask: 255.255.255.0\n          port_name: "proxyTranscoder_in"\n        latency: 30ms\n        bandwidth: 130MB/s\n        jitter: 500ms\n        multicast:\n          multicastAddrIP: 255.2.2.0\n          multicastAddrPort: 3000\n</file>
</plan>
``` 

Responses (XML String):

```XML
<result>
 	<status>Fail</status>
 	<info>$REASON</info>
 </result>
```

```XML
<result>
 <status>Success</status>
 <info>$INFO</info>
 <file name="Planned_tosca_file_a.yaml" level="1">$Planned_tosca_file_a</file>
 <file name="Planned_tosca_file_all.yaml" level="0">$Planned_tosca_file_all</file>
</result>
```
## Provisioner REST API

Operation: Register a user account.
```
http://$REST_SERVER:8080/REST_Provisioner/switch/account/register
```
Input parameter (XML String):
```XML
<register>
    <user>test</user>
    <pwd>1234</pwd>
</register>
```

Responses (String):

```
"Fail: xxxx"
```

```
"Success: xxxx"
```
Operation: Configure the user's EC2 account.

URL:
http://$REST_SERVER:8080/REST_Provisioner/switch/account/configure/ec2
Input parameter (XML String):
```XML
<configure>
    <user>test</user>
    <pwd>1234</pwd>
    <keyid>AKISAKISAKIS</keyid>
    <key>6J76J76J76J76J76J76J7</key>
    <loginKey domain_name="Virginia" >sdds\nsdf</loginKey>
    <loginKey domain_name="California" >sdds\nssdfdf\n</loginKey>
</configure> 
```

The **<loginKey>** node has the contents of the PEM certificates with all new lines replaced with the '\n' character. 
Example: 
```XML
<configure>
    <user>test</user>
    <pwd>123</pwd>
    <keyid>AKISAKISAKIS</keyid>
    <key>6J76J76J76J76J76J76J7</key>
    <loginKey domain_name="Virginia"> -----BEGIN RSA PRIVATE KEY-----\nMIIFDjBABgkqhkiG9w0BBQ0wMzAbBgkqhkiG9w0BBQwwDg\nMBQGCCqGSIb3DQMHBAgD1kGN4ZslJgSCBMi1xk9jhlPxPc\n9g73NQbtqZwI+9X5OhpSg/2ALxlCCjbqvzg=\n-----END RSA PRIVATE KEY----- </loginKey>
    <loginKey domain_name="CaliforniaCopy"> -----BEGIN RSA PRIVATE KEY-----\nMIIFDjBABgkqhkiG9w0BBQ0wMzAbBgkqhkiG9w0BBQwwDg\nMBQGCCqGSIb3DQMHBAgD1kGN4ZslJgSCBMi1xk9jhlPxPc\n9g73NQbtqZwI+9X5OhpSg/2ALxlCCjbqvzg=\n-----END RSA PRIVATE KEY-----  </loginKey>
</configure>
```
Responses (String):
```
"Fail: xxxx"
```

```
"Success: xxxx"
```

Operation: Configure the user's ExoGENI account.
```
http://$REST_SERVER:8080/REST_Provisioner/switch/account/configure/geni
```
Input parameter (XML String):

```XML
<configure>
    <user>test</user>
    <pwd>1234</pwd>
    <geniKey>1234\nfg\n</geniKey>
    <geniKeyAlias>geni</geniKeyAlias>
    <geniKeyPass>123456</geniKeyPass>
    <loginPubKey>1234\nfg\nss\n</loginPubKey>
    <loginPriKey>1234\nfg\nsdfs\n</loginPriKey>
</configure> 
```
Nodes `<loginPubKey>` and `<loginPriKey>` must also replace all new lines with the '\n' character 

Responses (String):
```
"Fail: xxxx"
```

```
"Success: xxxx"
```


Operation: Upload the infrastructure description files (TOSCA).
```
http://$REST_SERVER:8080/REST_Provisioner/switch/provision/upload
```

Input parameter (XML String):
```XML
<upload>
    <user>test</user>
    <pwd>1234</pwd>
    <file name='zh_a.yml' level='1'>tosca_a</file>
    <file name='zh_b.yml' level='1'>tosca_b</file>
    <file name='zh_all.yml' level='0'>tosca</file>
</upload>
```
Responses (String):
```
"Fail: xxxx"
```

```
"Success: Infrastructure files are uploaded! Action number: $AN"
```

There are two levels of description files for topologies designed by users. If the level attribute for the element file is 1, then this file is the top-level description, which defines how the sub-topologies are connected to each other. If the level attribute is 0, then the file is the low-level description, which describes the topology in one data center in detail. On the other hand, the name of low-level description file must be the sub-topology name appeared in the high-level description file. (For example, here should be zh_a and zh_b.)

For the output, $AN represents the action number returned by the server. It is an indexed number for user to identify his topologies files. It will also be used to execute provisioning. 


Operation: Upload the public key which the user want to use to access all his instances. (Optional)
```
http://$REST_SERVER:8080/REST_Provisioner/switch/provision/confuserkey
```

Input parameter (XML String):
```XML
<confUserKey>
    <user>test</user>
    <pwd>1234</pwd>
    <userKey name='id_dsa.pub'>tosca\nsdfsdf\n</userKey>
    <action>1479928399024</action>
</confUserKey>
```
Responses (String):

```
"Fail: $REASON"
```

```
"Success: $INFO"
```

This is an optional operation. This operation must be invoked before executing provisioning, only when the field `publicKeyPath` or `userName` is not `null` in the TOSCA file. It means that if the user wants to access all the instances with his own private key and user name, he must upload his corresponding public key first.

Upload the script that the user wants to use. (Optional)
```
http://$REST_SERVER:8080/REST_Provisioner/switch/provision/confscript
```
```XML
<confScript>
    <user>test</user>
    <pwd>1234</pwd>
    <script> #!/bin/bash\ndir=$(dirname "$0")\ntouch test.txt\n</script>
    <action>1479928399024</action>
</confScript >
```

Responses (String):
```
Fail: $REASON
```
```
Success: script for GUI is uploaded!
```


Operation: Execute provisioning for a specified action number.
```
http://$REST_SERVER:8080/REST_Provisioner/switch/provision/execute
```

Input parameter (XML String):
```XML
<execute>
    <user>test</user>
    <pwd>1234</pwd>
    <action>1481238226760</action>
</execute>
```

Responses (XML String):
```XML
<result>
    <status>Fail</status>
    <info>$REASON</info>
</result>
```
```XML
<result>
    <status>Success</status>
    <info>$INFO</info>
    <file>$Provisioned_tosca_file_a</file>
    <file>$Provisioned_tosca_file_b</file>
</result>
```

The returned file of $Provisioned_tosca_file_a is the provisioned TOSCA file. They contain the public address information of the instances. 
The new line symbol in the text of element of file is still represented as "\n".


## Deployment agent


Operation: Deploy a kubernetes cluster.
```
http://$REST_SERVER:8080/REST_Provisioner/switch/deploy/kubernetes
```

Input parameter (XML String):
```XML
<deploy>
    <user>test</user>
    <pwd>1234</pwd>
    <action>1481238226760</action>
</deploy>
```

Responses  (XML String):
```XML
<result>
    <status>Fail</status>
    <info>$REASON</info>
</result>
```
```XML
<result>
    <status>Success</status>
    <info>$INFO</info>
    <file>$ADMIN_CONF_FILE</file>
</result>
```


# More

More information can be found on the project's [wiki](https://github.com/QCAPI-DRIP/DRIP-integradation/wiki)
