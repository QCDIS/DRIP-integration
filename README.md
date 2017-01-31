# About DRIP 

The Dynamic Real-time infrastructure planner (DRIP) allows application developers to seamlessly plan a customized virtual infrastructure based on application level constraints on QoS and resource budgets, provisioning the virtual infrastructure using standardized interfaces (e.g., TOSCA and OCCI), deploy application components onto the virtual infrastructure, and start execution on demand.
 
DRIP is developed by the research team for Quality Critical Applications on Programmable Infrastructure (QCAPI) in the [System and Network Engineering Research Group (SNE)](https://ivi.fnwi.uva.nl/sne/) of the University of Amsterdam. The development of DRIP is coordinated by Dr. Zhiming Zhao. Core developers include Junchao Wang, Huan Zhou, Yang Hu, Paul Martin, Arie Taal and Spiros Koulouzis.
 
The DRIP components are made available as open source under the Apache 2.0 license; the software has been containerized and can be provisioned and deployed on federated virtual infrastructures. The development of DRIP is supported by the European Union Horizon 2020 research and innovation program under grant agreements No. 643963 ([SWITCH](http://www.switchproject.eu/)).

# Architecture and key components

The DRIP system contains a number of micro services (agents):

![](https://staff.fnwi.uva.nl/z.zhao/software/drip/index_files/image002.png)

DRIP has a number of key components:

1. The DRIP manager will be implemented as a Web service that allows DRIP functions to be invoked individually or in tandem by outside clients via a RESTful interface.
2. The infrastructure planner (planning agent) will use an adapted partial critical path algorithm to produce efficient infrastructure topologies based on application workflows specified in YAML in compliance with the TOSCA specification.
3. The infrastructure provisioner (provisioning agent) takes the infrastructure plans produced by the planner using TOSCA as input, and directs the provisioning of virtual infrastructure onto underlying infrastructure services. It uses OCCI as default provisioning interface, and currently has been tested on ExoGENI, EC2 and EGI FedCloud.
4. The deployment agent installs application components onto provisioned infrastructure.
5. Discovery agents periodically update cloud provider information used for the planning and provisioning of infrastructure (including resource types), and helps acquire information regarding the performance of particular application components on specific resource types to put into the knowledge base.
6. A knowledge base uses the semantic models developed in the SWITCH and ENVRIPLUS projects, and maintains the descriptions of the cloud providers, resource types, performance characteristics, and other relevant information. The knowledge base also provides an interface for these agents to look up providers, resources and runtime status data during the execution of an application.
7. A number of control agents provide access to the underlying programmability provided by the virtual infrastructures, e.g., horizontal and vertical scaling of virtual machines, by providing interfaces by which the infrastructure hosting an application can be dynamically manipulated at runtime.

# Support

The DRIP system is developed using the Apache license version 2.0. It is open source, and there is no warrant on the software quality. We welcome any suggestions on software features, use-cases and joint research activities. Please contact us via email: z.zhao@uva.nl.

![](https://raw.githubusercontent.com/QCAPI-DRIP/DRIP-integradation/master/images/logo-sne-big-flat_100x75.png)
![](https://github.com/QCAPI-DRIP/DRIP-integradation/blob/master/images/switch_100x100.png)
