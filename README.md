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


# More

More information can be found on the project's [wiki](https://github.com/QCAPI-DRIP/DRIP-integradation/wiki)
