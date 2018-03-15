1. Download the project from: https://github.com/QCAPI-DRIP/DRIP-integration/archive/master.zip
2. Unzip and got to `DRIP-integration-master`
3. Open the file `env_file` and replce the two variables `keystorePass` and `KEYSTORE_URL` ([this](https://tomcat.apache.org/tomcat-7.0-doc/ssl-howto.html) link tells you how to create a keystore)
4. Run: `docker-compose -f docker-compose.yml up -d` to start all srevices
5. Look at https://localhost:8443/drip-api/?wadl for a desciption of the drip-api. The documentation of the API can be found [here](https://qcapi-drip.github.io/DRIP-integration/index.html)
