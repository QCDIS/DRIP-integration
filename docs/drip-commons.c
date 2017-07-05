#include <enunciate-common.c>
#ifndef DEF_drip_commons_ns0_attribute_H
#define DEF_drip_commons_ns0_attribute_H

/**
 * 
 *  @author S. Koulouzis
 */
struct drip_commons_ns0_attribute {


  /**
   * Name of the file/public key.
   */
  xmlChar *name;

  /**
   * There are two levels of description files for topologies designed by users.
   * If the level attribute for the element file is 1, then this file is the top-level description,
   * which defines how the sub-topologies are connected to each other.
   * If the level attribute is 0, then the file is the low-level description,
   * which describes the topology in one data center in detail.
   * On the other hand, the name of low-level description file must be the
   * sub-topology name appeared in the high-level description file. (For example, here should be zh_a and zh_b.)
   */
  xmlChar *level;

  /**
   * (no documentation provided)
   */
  xmlChar *content;
};

/**
 * Reads a Attribute from XML. The reader is assumed to be at the start element.
 *
 * @param reader The XML reader.
 * @return The Attribute, or NULL in case of error.
 */
static struct drip_commons_ns0_attribute *xmlTextReaderReadNs0AttributeType(xmlTextReaderPtr reader);

/**
 * Writes a Attribute to XML.
 *
 * @param writer The XML writer.
 * @param _attribute The Attribute to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0AttributeType(xmlTextWriterPtr writer, struct drip_commons_ns0_attribute *_attribute);

/**
 * Frees the elements of a Attribute.
 *
 * @param _attribute The Attribute to free.
 */
static void freeNs0AttributeType(struct drip_commons_ns0_attribute *_attribute);

#endif /* DEF_drip_commons_ns0_attribute_H */
#ifndef DEF_drip_commons_ns0_confScript_H
#define DEF_drip_commons_ns0_confScript_H

/**
 * 
 *  @author S. Koulouzis
 */
struct drip_commons_ns0_confScript {


  /**
   * Not used. It's there for backwards compatibility.
   */
  xmlChar *user;

  /**
   * Not used. It's there for backwards compatibility.
   */
  xmlChar *pwd;

  /**
   * A referance id used from the servcie to do the provisioning
   */
  xmlChar *action;

  /**
   * The script contents with new lines replace by '\n'
   */
  xmlChar *script;
};

/**
 * Reads a ConfScript element from XML. The element to be read is "confScript", and
 * it is assumed that the reader is pointing to the XML document (not the element).
 *
 * @param reader The XML reader.
 * @return The ConfScript, or NULL in case of error.
 */
struct drip_commons_ns0_confScript *xml_read_drip_commons_ns0_confScript(xmlTextReaderPtr reader);

/**
 * Writes a ConfScript to XML under element name "confScript".
 *
 * @param writer The XML writer.
 * @param _confScript The ConfScript to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
int xml_write_drip_commons_ns0_confScript(xmlTextWriterPtr writer, struct drip_commons_ns0_confScript *_confScript);

/**
 * Frees a ConfScript.
 *
 * @param _confScript The ConfScript to free.
 */
void free_drip_commons_ns0_confScript(struct drip_commons_ns0_confScript *_confScript);

/**
 * Reads a ConfScript element from XML. The element to be read is "confScript", and
 * it is assumed that the reader is already pointing to the element.
 *
 * @param reader The XML reader.
 * @return The ConfScript, or NULL in case of error.
 */
struct drip_commons_ns0_confScript *xmlTextReaderReadNs0ConfScriptElement(xmlTextReaderPtr reader);

/**
 * Writes a ConfScript to XML under element name "confScript".
 * Does NOT write the namespace prefixes.
 *
 * @param writer The XML writer.
 * @param _confScript The ConfScript to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0ConfScriptElement(xmlTextWriterPtr writer, struct drip_commons_ns0_confScript *_confScript);

/**
 * Writes a ConfScript to XML under element name "confScript".
 *
 * @param writer The XML writer.
 * @param _confScript The ConfScript to write.
 * @param writeNamespaces Whether to write the namespace prefixes.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0ConfScriptElementNS(xmlTextWriterPtr writer, struct drip_commons_ns0_confScript *_confScript, int writeNamespaces);

/**
 * Frees the children of a ConfScript.
 *
 * @param _confScript The ConfScript whose children are to be free.
 */
static void freeNs0ConfScriptElement(struct drip_commons_ns0_confScript *_confScript);

/**
 * Reads a ConfScript from XML. The reader is assumed to be at the start element.
 *
 * @param reader The XML reader.
 * @return The ConfScript, or NULL in case of error.
 */
static struct drip_commons_ns0_confScript *xmlTextReaderReadNs0ConfScriptType(xmlTextReaderPtr reader);

/**
 * Writes a ConfScript to XML.
 *
 * @param writer The XML writer.
 * @param _confScript The ConfScript to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0ConfScriptType(xmlTextWriterPtr writer, struct drip_commons_ns0_confScript *_confScript);

/**
 * Frees the elements of a ConfScript.
 *
 * @param _confScript The ConfScript to free.
 */
static void freeNs0ConfScriptType(struct drip_commons_ns0_confScript *_confScript);

#endif /* DEF_drip_commons_ns0_confScript_H */
#ifndef DEF_drip_commons_ns0_confUserKey_H
#define DEF_drip_commons_ns0_confUserKey_H

/**
 * 
 *  @author S. Koulouzis
 */
struct drip_commons_ns0_confUserKey {


  /**
   * Not used. It's there for backwards compatibility.
   */
  xmlChar *user;

  /**
   * Not used. It's there for backwards compatibility.
   */
  xmlChar *pwd;

  /**
   * A referance id used from the servcie to do the provisioning
   */
  xmlChar *action;

  /**
   * (no documentation provided)
   */
  struct drip_commons_ns0_attribute *file;

  /**
   * Size of the file array.
   */
  int _sizeof_file;
};

/**
 * Reads a ConfUserKey element from XML. The element to be read is "confUserKey", and
 * it is assumed that the reader is pointing to the XML document (not the element).
 *
 * @param reader The XML reader.
 * @return The ConfUserKey, or NULL in case of error.
 */
struct drip_commons_ns0_confUserKey *xml_read_drip_commons_ns0_confUserKey(xmlTextReaderPtr reader);

/**
 * Writes a ConfUserKey to XML under element name "confUserKey".
 *
 * @param writer The XML writer.
 * @param _confUserKey The ConfUserKey to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
int xml_write_drip_commons_ns0_confUserKey(xmlTextWriterPtr writer, struct drip_commons_ns0_confUserKey *_confUserKey);

/**
 * Frees a ConfUserKey.
 *
 * @param _confUserKey The ConfUserKey to free.
 */
void free_drip_commons_ns0_confUserKey(struct drip_commons_ns0_confUserKey *_confUserKey);

/**
 * Reads a ConfUserKey element from XML. The element to be read is "confUserKey", and
 * it is assumed that the reader is already pointing to the element.
 *
 * @param reader The XML reader.
 * @return The ConfUserKey, or NULL in case of error.
 */
struct drip_commons_ns0_confUserKey *xmlTextReaderReadNs0ConfUserKeyElement(xmlTextReaderPtr reader);

/**
 * Writes a ConfUserKey to XML under element name "confUserKey".
 * Does NOT write the namespace prefixes.
 *
 * @param writer The XML writer.
 * @param _confUserKey The ConfUserKey to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0ConfUserKeyElement(xmlTextWriterPtr writer, struct drip_commons_ns0_confUserKey *_confUserKey);

/**
 * Writes a ConfUserKey to XML under element name "confUserKey".
 *
 * @param writer The XML writer.
 * @param _confUserKey The ConfUserKey to write.
 * @param writeNamespaces Whether to write the namespace prefixes.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0ConfUserKeyElementNS(xmlTextWriterPtr writer, struct drip_commons_ns0_confUserKey *_confUserKey, int writeNamespaces);

/**
 * Frees the children of a ConfUserKey.
 *
 * @param _confUserKey The ConfUserKey whose children are to be free.
 */
static void freeNs0ConfUserKeyElement(struct drip_commons_ns0_confUserKey *_confUserKey);

/**
 * Reads a ConfUserKey from XML. The reader is assumed to be at the start element.
 *
 * @param reader The XML reader.
 * @return The ConfUserKey, or NULL in case of error.
 */
static struct drip_commons_ns0_confUserKey *xmlTextReaderReadNs0ConfUserKeyType(xmlTextReaderPtr reader);

/**
 * Writes a ConfUserKey to XML.
 *
 * @param writer The XML writer.
 * @param _confUserKey The ConfUserKey to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0ConfUserKeyType(xmlTextWriterPtr writer, struct drip_commons_ns0_confUserKey *_confUserKey);

/**
 * Frees the elements of a ConfUserKey.
 *
 * @param _confUserKey The ConfUserKey to free.
 */
static void freeNs0ConfUserKeyType(struct drip_commons_ns0_confUserKey *_confUserKey);

#endif /* DEF_drip_commons_ns0_confUserKey_H */
#ifndef DEF_drip_commons_ns0_configure_H
#define DEF_drip_commons_ns0_configure_H

/**
 * 
 *  @author S. Koulouzis
 */
struct drip_commons_ns0_configure {


  /**
   * Not used. It's there for backwards compatibility.
   */
  xmlChar *user;

  /**
   * Not used. It's there for backwards compatibility.
   */
  xmlChar *pwd;

  /**
   * The key id for the cloud provider.
   */
  xmlChar *keyid;

  /**
   * The key for the cloud provider.
   */
  xmlChar *key;

  /**
   * (no documentation provided)
   */
  struct drip_commons_ns0_loginKey0 *loginKey;

  /**
   * Size of the loginKey array.
   */
  int _sizeof_loginKey;

  /**
   * The binary keystore (user.jks) for the cloud provider encoded in base64
   */
  xmlChar *geniKey;

  /**
   * Key alias in key store
   */
  xmlChar *geniKeyAlias;

  /**
   * (no documentation provided)
   */
  struct drip_commons_ns0_loginKey0 *loginPubKey;

  /**
   * Size of the loginPubKey array.
   */
  int _sizeof_loginPubKey;

  /**
   * (no documentation provided)
   */
  xmlChar *geniKeyPass;

  /**
   * (no documentation provided)
   */
  struct drip_commons_ns0_loginKey0 *loginPriKey;

  /**
   * Size of the loginPriKey array.
   */
  int _sizeof_loginPriKey;
};

/**
 * Reads a Configure element from XML. The element to be read is "configure", and
 * it is assumed that the reader is pointing to the XML document (not the element).
 *
 * @param reader The XML reader.
 * @return The Configure, or NULL in case of error.
 */
struct drip_commons_ns0_configure *xml_read_drip_commons_ns0_configure(xmlTextReaderPtr reader);

/**
 * Writes a Configure to XML under element name "configure".
 *
 * @param writer The XML writer.
 * @param _configure The Configure to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
int xml_write_drip_commons_ns0_configure(xmlTextWriterPtr writer, struct drip_commons_ns0_configure *_configure);

/**
 * Frees a Configure.
 *
 * @param _configure The Configure to free.
 */
void free_drip_commons_ns0_configure(struct drip_commons_ns0_configure *_configure);

/**
 * Reads a Configure element from XML. The element to be read is "configure", and
 * it is assumed that the reader is already pointing to the element.
 *
 * @param reader The XML reader.
 * @return The Configure, or NULL in case of error.
 */
struct drip_commons_ns0_configure *xmlTextReaderReadNs0ConfigureElement(xmlTextReaderPtr reader);

/**
 * Writes a Configure to XML under element name "configure".
 * Does NOT write the namespace prefixes.
 *
 * @param writer The XML writer.
 * @param _configure The Configure to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0ConfigureElement(xmlTextWriterPtr writer, struct drip_commons_ns0_configure *_configure);

/**
 * Writes a Configure to XML under element name "configure".
 *
 * @param writer The XML writer.
 * @param _configure The Configure to write.
 * @param writeNamespaces Whether to write the namespace prefixes.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0ConfigureElementNS(xmlTextWriterPtr writer, struct drip_commons_ns0_configure *_configure, int writeNamespaces);

/**
 * Frees the children of a Configure.
 *
 * @param _configure The Configure whose children are to be free.
 */
static void freeNs0ConfigureElement(struct drip_commons_ns0_configure *_configure);

/**
 * Reads a Configure from XML. The reader is assumed to be at the start element.
 *
 * @param reader The XML reader.
 * @return The Configure, or NULL in case of error.
 */
static struct drip_commons_ns0_configure *xmlTextReaderReadNs0ConfigureType(xmlTextReaderPtr reader);

/**
 * Writes a Configure to XML.
 *
 * @param writer The XML writer.
 * @param _configure The Configure to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0ConfigureType(xmlTextWriterPtr writer, struct drip_commons_ns0_configure *_configure);

/**
 * Frees the elements of a Configure.
 *
 * @param _configure The Configure to free.
 */
static void freeNs0ConfigureType(struct drip_commons_ns0_configure *_configure);

#endif /* DEF_drip_commons_ns0_configure_H */
#ifndef DEF_drip_commons_ns0_deploy_H
#define DEF_drip_commons_ns0_deploy_H

/**
 * 
 *  @author S. Koulouzis
 */
struct drip_commons_ns0_deploy {


  /**
   * Not used. It's there for backwards compatibility.
   */
  xmlChar *user;

  /**
   * Not used. It's there for backwards compatibility.
   */
  xmlChar *pwd;

  /**
   * A referance id used from the servcie to do the provisioning
   */
  xmlChar *action;
};

/**
 * Reads a Deploy element from XML. The element to be read is "deploy", and
 * it is assumed that the reader is pointing to the XML document (not the element).
 *
 * @param reader The XML reader.
 * @return The Deploy, or NULL in case of error.
 */
struct drip_commons_ns0_deploy *xml_read_drip_commons_ns0_deploy(xmlTextReaderPtr reader);

/**
 * Writes a Deploy to XML under element name "deploy".
 *
 * @param writer The XML writer.
 * @param _deploy The Deploy to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
int xml_write_drip_commons_ns0_deploy(xmlTextWriterPtr writer, struct drip_commons_ns0_deploy *_deploy);

/**
 * Frees a Deploy.
 *
 * @param _deploy The Deploy to free.
 */
void free_drip_commons_ns0_deploy(struct drip_commons_ns0_deploy *_deploy);

/**
 * Reads a Deploy element from XML. The element to be read is "deploy", and
 * it is assumed that the reader is already pointing to the element.
 *
 * @param reader The XML reader.
 * @return The Deploy, or NULL in case of error.
 */
struct drip_commons_ns0_deploy *xmlTextReaderReadNs0DeployElement(xmlTextReaderPtr reader);

/**
 * Writes a Deploy to XML under element name "deploy".
 * Does NOT write the namespace prefixes.
 *
 * @param writer The XML writer.
 * @param _deploy The Deploy to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0DeployElement(xmlTextWriterPtr writer, struct drip_commons_ns0_deploy *_deploy);

/**
 * Writes a Deploy to XML under element name "deploy".
 *
 * @param writer The XML writer.
 * @param _deploy The Deploy to write.
 * @param writeNamespaces Whether to write the namespace prefixes.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0DeployElementNS(xmlTextWriterPtr writer, struct drip_commons_ns0_deploy *_deploy, int writeNamespaces);

/**
 * Frees the children of a Deploy.
 *
 * @param _deploy The Deploy whose children are to be free.
 */
static void freeNs0DeployElement(struct drip_commons_ns0_deploy *_deploy);

/**
 * Reads a Deploy from XML. The reader is assumed to be at the start element.
 *
 * @param reader The XML reader.
 * @return The Deploy, or NULL in case of error.
 */
static struct drip_commons_ns0_deploy *xmlTextReaderReadNs0DeployType(xmlTextReaderPtr reader);

/**
 * Writes a Deploy to XML.
 *
 * @param writer The XML writer.
 * @param _deploy The Deploy to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0DeployType(xmlTextWriterPtr writer, struct drip_commons_ns0_deploy *_deploy);

/**
 * Frees the elements of a Deploy.
 *
 * @param _deploy The Deploy to free.
 */
static void freeNs0DeployType(struct drip_commons_ns0_deploy *_deploy);

#endif /* DEF_drip_commons_ns0_deploy_H */
#ifndef DEF_drip_commons_ns0_execute_H
#define DEF_drip_commons_ns0_execute_H

/**
 * 
 *  @author S. Koulouzis
 */
struct drip_commons_ns0_execute {


  /**
   * Not used. It's there for backwards compatibility.
   */
  xmlChar *user;

  /**
   * Not used. It's there for backwards compatibility.
   */
  xmlChar *pwd;

  /**
   * A referance id used from the servcie to do the provisioning
   */
  xmlChar *action;
};

/**
 * Reads a Execute element from XML. The element to be read is "execute", and
 * it is assumed that the reader is pointing to the XML document (not the element).
 *
 * @param reader The XML reader.
 * @return The Execute, or NULL in case of error.
 */
struct drip_commons_ns0_execute *xml_read_drip_commons_ns0_execute(xmlTextReaderPtr reader);

/**
 * Writes a Execute to XML under element name "execute".
 *
 * @param writer The XML writer.
 * @param _execute The Execute to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
int xml_write_drip_commons_ns0_execute(xmlTextWriterPtr writer, struct drip_commons_ns0_execute *_execute);

/**
 * Frees a Execute.
 *
 * @param _execute The Execute to free.
 */
void free_drip_commons_ns0_execute(struct drip_commons_ns0_execute *_execute);

/**
 * Reads a Execute element from XML. The element to be read is "execute", and
 * it is assumed that the reader is already pointing to the element.
 *
 * @param reader The XML reader.
 * @return The Execute, or NULL in case of error.
 */
struct drip_commons_ns0_execute *xmlTextReaderReadNs0ExecuteElement(xmlTextReaderPtr reader);

/**
 * Writes a Execute to XML under element name "execute".
 * Does NOT write the namespace prefixes.
 *
 * @param writer The XML writer.
 * @param _execute The Execute to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0ExecuteElement(xmlTextWriterPtr writer, struct drip_commons_ns0_execute *_execute);

/**
 * Writes a Execute to XML under element name "execute".
 *
 * @param writer The XML writer.
 * @param _execute The Execute to write.
 * @param writeNamespaces Whether to write the namespace prefixes.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0ExecuteElementNS(xmlTextWriterPtr writer, struct drip_commons_ns0_execute *_execute, int writeNamespaces);

/**
 * Frees the children of a Execute.
 *
 * @param _execute The Execute whose children are to be free.
 */
static void freeNs0ExecuteElement(struct drip_commons_ns0_execute *_execute);

/**
 * Reads a Execute from XML. The reader is assumed to be at the start element.
 *
 * @param reader The XML reader.
 * @return The Execute, or NULL in case of error.
 */
static struct drip_commons_ns0_execute *xmlTextReaderReadNs0ExecuteType(xmlTextReaderPtr reader);

/**
 * Writes a Execute to XML.
 *
 * @param writer The XML writer.
 * @param _execute The Execute to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0ExecuteType(xmlTextWriterPtr writer, struct drip_commons_ns0_execute *_execute);

/**
 * Frees the elements of a Execute.
 *
 * @param _execute The Execute to free.
 */
static void freeNs0ExecuteType(struct drip_commons_ns0_execute *_execute);

#endif /* DEF_drip_commons_ns0_execute_H */
#ifndef DEF_drip_commons_ns0_loginKey0_H
#define DEF_drip_commons_ns0_loginKey0_H

/**
 * 
 *  @author S. Koulouzis
 */
struct drip_commons_ns0_loginKey0 {


  /**
   * (no documentation provided)
   */
  xmlChar *domain_name;

  /**
   * (no documentation provided)
   */
  xmlChar *content;
};

/**
 * Reads a LoginKey0 from XML. The reader is assumed to be at the start element.
 *
 * @param reader The XML reader.
 * @return The LoginKey0, or NULL in case of error.
 */
static struct drip_commons_ns0_loginKey0 *xmlTextReaderReadNs0LoginKey0Type(xmlTextReaderPtr reader);

/**
 * Writes a LoginKey0 to XML.
 *
 * @param writer The XML writer.
 * @param _loginKey0 The LoginKey0 to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0LoginKey0Type(xmlTextWriterPtr writer, struct drip_commons_ns0_loginKey0 *_loginKey0);

/**
 * Frees the elements of a LoginKey0.
 *
 * @param _loginKey0 The LoginKey0 to free.
 */
static void freeNs0LoginKey0Type(struct drip_commons_ns0_loginKey0 *_loginKey0);

#endif /* DEF_drip_commons_ns0_loginKey0_H */
#ifndef DEF_drip_commons_ns0_plan_H
#define DEF_drip_commons_ns0_plan_H

/**
 * 
 *  This class represents a plan to be provided to the planner.
 * 
 *  @author S. Koulouzis
 */
struct drip_commons_ns0_plan {


  /**
   * Not used. It's only there for backwords compatibility
   */
  xmlChar *user;

  /**
   * Not used. It's only there for backwords compatibility
   */
  xmlChar *pwd;

  /**
   * The contents of the TOSCA description
   */
  xmlChar *file;
};

/**
 * Reads a Plan element from XML. The element to be read is "plan", and
 * it is assumed that the reader is pointing to the XML document (not the element).
 *
 * @param reader The XML reader.
 * @return The Plan, or NULL in case of error.
 */
struct drip_commons_ns0_plan *xml_read_drip_commons_ns0_plan(xmlTextReaderPtr reader);

/**
 * Writes a Plan to XML under element name "plan".
 *
 * @param writer The XML writer.
 * @param _plan The Plan to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
int xml_write_drip_commons_ns0_plan(xmlTextWriterPtr writer, struct drip_commons_ns0_plan *_plan);

/**
 * Frees a Plan.
 *
 * @param _plan The Plan to free.
 */
void free_drip_commons_ns0_plan(struct drip_commons_ns0_plan *_plan);

/**
 * Reads a Plan element from XML. The element to be read is "plan", and
 * it is assumed that the reader is already pointing to the element.
 *
 * @param reader The XML reader.
 * @return The Plan, or NULL in case of error.
 */
struct drip_commons_ns0_plan *xmlTextReaderReadNs0PlanElement(xmlTextReaderPtr reader);

/**
 * Writes a Plan to XML under element name "plan".
 * Does NOT write the namespace prefixes.
 *
 * @param writer The XML writer.
 * @param _plan The Plan to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0PlanElement(xmlTextWriterPtr writer, struct drip_commons_ns0_plan *_plan);

/**
 * Writes a Plan to XML under element name "plan".
 *
 * @param writer The XML writer.
 * @param _plan The Plan to write.
 * @param writeNamespaces Whether to write the namespace prefixes.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0PlanElementNS(xmlTextWriterPtr writer, struct drip_commons_ns0_plan *_plan, int writeNamespaces);

/**
 * Frees the children of a Plan.
 *
 * @param _plan The Plan whose children are to be free.
 */
static void freeNs0PlanElement(struct drip_commons_ns0_plan *_plan);

/**
 * Reads a Plan from XML. The reader is assumed to be at the start element.
 *
 * @param reader The XML reader.
 * @return The Plan, or NULL in case of error.
 */
static struct drip_commons_ns0_plan *xmlTextReaderReadNs0PlanType(xmlTextReaderPtr reader);

/**
 * Writes a Plan to XML.
 *
 * @param writer The XML writer.
 * @param _plan The Plan to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0PlanType(xmlTextWriterPtr writer, struct drip_commons_ns0_plan *_plan);

/**
 * Frees the elements of a Plan.
 *
 * @param _plan The Plan to free.
 */
static void freeNs0PlanType(struct drip_commons_ns0_plan *_plan);

#endif /* DEF_drip_commons_ns0_plan_H */
#ifndef DEF_drip_commons_ns0_register_H
#define DEF_drip_commons_ns0_register_H

/**
 * 
 *  @author S. Koulouzis
 */
struct drip_commons_ns0_register {


  /**
   * The user name
   */
  xmlChar *user;

  /**
   * The user password
   */
  xmlChar *pwd;
};

/**
 * Reads a Register element from XML. The element to be read is "register", and
 * it is assumed that the reader is pointing to the XML document (not the element).
 *
 * @param reader The XML reader.
 * @return The Register, or NULL in case of error.
 */
struct drip_commons_ns0_register *xml_read_drip_commons_ns0_register(xmlTextReaderPtr reader);

/**
 * Writes a Register to XML under element name "register".
 *
 * @param writer The XML writer.
 * @param _register The Register to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
int xml_write_drip_commons_ns0_register(xmlTextWriterPtr writer, struct drip_commons_ns0_register *_register);

/**
 * Frees a Register.
 *
 * @param _register The Register to free.
 */
void free_drip_commons_ns0_register(struct drip_commons_ns0_register *_register);

/**
 * Reads a Register element from XML. The element to be read is "register", and
 * it is assumed that the reader is already pointing to the element.
 *
 * @param reader The XML reader.
 * @return The Register, or NULL in case of error.
 */
struct drip_commons_ns0_register *xmlTextReaderReadNs0RegisterElement(xmlTextReaderPtr reader);

/**
 * Writes a Register to XML under element name "register".
 * Does NOT write the namespace prefixes.
 *
 * @param writer The XML writer.
 * @param _register The Register to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0RegisterElement(xmlTextWriterPtr writer, struct drip_commons_ns0_register *_register);

/**
 * Writes a Register to XML under element name "register".
 *
 * @param writer The XML writer.
 * @param _register The Register to write.
 * @param writeNamespaces Whether to write the namespace prefixes.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0RegisterElementNS(xmlTextWriterPtr writer, struct drip_commons_ns0_register *_register, int writeNamespaces);

/**
 * Frees the children of a Register.
 *
 * @param _register The Register whose children are to be free.
 */
static void freeNs0RegisterElement(struct drip_commons_ns0_register *_register);

/**
 * Reads a Register from XML. The reader is assumed to be at the start element.
 *
 * @param reader The XML reader.
 * @return The Register, or NULL in case of error.
 */
static struct drip_commons_ns0_register *xmlTextReaderReadNs0RegisterType(xmlTextReaderPtr reader);

/**
 * Writes a Register to XML.
 *
 * @param writer The XML writer.
 * @param _register The Register to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0RegisterType(xmlTextWriterPtr writer, struct drip_commons_ns0_register *_register);

/**
 * Frees the elements of a Register.
 *
 * @param _register The Register to free.
 */
static void freeNs0RegisterType(struct drip_commons_ns0_register *_register);

#endif /* DEF_drip_commons_ns0_register_H */
#ifndef DEF_drip_commons_ns0_result_H
#define DEF_drip_commons_ns0_result_H

/**
 * 
 *  @author S. Koulouzis
 */
struct drip_commons_ns0_result {


  /**
   * The status of the response
   */
  xmlChar *status;

  /**
   * Not used. Not used. It's there for backwards compatibility.
   */
  xmlChar *info;

  /**
   * (no documentation provided)
   */
  struct drip_commons_ns0_attribute *file;

  /**
   * Size of the file array.
   */
  int _sizeof_file;
};

/**
 * Reads a Result element from XML. The element to be read is "result", and
 * it is assumed that the reader is pointing to the XML document (not the element).
 *
 * @param reader The XML reader.
 * @return The Result, or NULL in case of error.
 */
struct drip_commons_ns0_result *xml_read_drip_commons_ns0_result(xmlTextReaderPtr reader);

/**
 * Writes a Result to XML under element name "result".
 *
 * @param writer The XML writer.
 * @param _result The Result to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
int xml_write_drip_commons_ns0_result(xmlTextWriterPtr writer, struct drip_commons_ns0_result *_result);

/**
 * Frees a Result.
 *
 * @param _result The Result to free.
 */
void free_drip_commons_ns0_result(struct drip_commons_ns0_result *_result);

/**
 * Reads a Result element from XML. The element to be read is "result", and
 * it is assumed that the reader is already pointing to the element.
 *
 * @param reader The XML reader.
 * @return The Result, or NULL in case of error.
 */
struct drip_commons_ns0_result *xmlTextReaderReadNs0ResultElement(xmlTextReaderPtr reader);

/**
 * Writes a Result to XML under element name "result".
 * Does NOT write the namespace prefixes.
 *
 * @param writer The XML writer.
 * @param _result The Result to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0ResultElement(xmlTextWriterPtr writer, struct drip_commons_ns0_result *_result);

/**
 * Writes a Result to XML under element name "result".
 *
 * @param writer The XML writer.
 * @param _result The Result to write.
 * @param writeNamespaces Whether to write the namespace prefixes.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0ResultElementNS(xmlTextWriterPtr writer, struct drip_commons_ns0_result *_result, int writeNamespaces);

/**
 * Frees the children of a Result.
 *
 * @param _result The Result whose children are to be free.
 */
static void freeNs0ResultElement(struct drip_commons_ns0_result *_result);

/**
 * Reads a Result from XML. The reader is assumed to be at the start element.
 *
 * @param reader The XML reader.
 * @return The Result, or NULL in case of error.
 */
static struct drip_commons_ns0_result *xmlTextReaderReadNs0ResultType(xmlTextReaderPtr reader);

/**
 * Writes a Result to XML.
 *
 * @param writer The XML writer.
 * @param _result The Result to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0ResultType(xmlTextWriterPtr writer, struct drip_commons_ns0_result *_result);

/**
 * Frees the elements of a Result.
 *
 * @param _result The Result to free.
 */
static void freeNs0ResultType(struct drip_commons_ns0_result *_result);

#endif /* DEF_drip_commons_ns0_result_H */
#ifndef DEF_drip_commons_ns0_upload_H
#define DEF_drip_commons_ns0_upload_H

/**
 * 
 *  @author S. Koulouzis
 */
struct drip_commons_ns0_upload {


  /**
   * (no documentation provided)
   */
  xmlChar *user;

  /**
   * (no documentation provided)
   */
  xmlChar *pwd;

  /**
   * (no documentation provided)
   */
  struct drip_commons_ns0_attribute *file;

  /**
   * Size of the file array.
   */
  int _sizeof_file;
};

/**
 * Reads a Upload element from XML. The element to be read is "upload", and
 * it is assumed that the reader is pointing to the XML document (not the element).
 *
 * @param reader The XML reader.
 * @return The Upload, or NULL in case of error.
 */
struct drip_commons_ns0_upload *xml_read_drip_commons_ns0_upload(xmlTextReaderPtr reader);

/**
 * Writes a Upload to XML under element name "upload".
 *
 * @param writer The XML writer.
 * @param _upload The Upload to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
int xml_write_drip_commons_ns0_upload(xmlTextWriterPtr writer, struct drip_commons_ns0_upload *_upload);

/**
 * Frees a Upload.
 *
 * @param _upload The Upload to free.
 */
void free_drip_commons_ns0_upload(struct drip_commons_ns0_upload *_upload);

/**
 * Reads a Upload element from XML. The element to be read is "upload", and
 * it is assumed that the reader is already pointing to the element.
 *
 * @param reader The XML reader.
 * @return The Upload, or NULL in case of error.
 */
struct drip_commons_ns0_upload *xmlTextReaderReadNs0UploadElement(xmlTextReaderPtr reader);

/**
 * Writes a Upload to XML under element name "upload".
 * Does NOT write the namespace prefixes.
 *
 * @param writer The XML writer.
 * @param _upload The Upload to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0UploadElement(xmlTextWriterPtr writer, struct drip_commons_ns0_upload *_upload);

/**
 * Writes a Upload to XML under element name "upload".
 *
 * @param writer The XML writer.
 * @param _upload The Upload to write.
 * @param writeNamespaces Whether to write the namespace prefixes.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0UploadElementNS(xmlTextWriterPtr writer, struct drip_commons_ns0_upload *_upload, int writeNamespaces);

/**
 * Frees the children of a Upload.
 *
 * @param _upload The Upload whose children are to be free.
 */
static void freeNs0UploadElement(struct drip_commons_ns0_upload *_upload);

/**
 * Reads a Upload from XML. The reader is assumed to be at the start element.
 *
 * @param reader The XML reader.
 * @return The Upload, or NULL in case of error.
 */
static struct drip_commons_ns0_upload *xmlTextReaderReadNs0UploadType(xmlTextReaderPtr reader);

/**
 * Writes a Upload to XML.
 *
 * @param writer The XML writer.
 * @param _upload The Upload to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteNs0UploadType(xmlTextWriterPtr writer, struct drip_commons_ns0_upload *_upload);

/**
 * Frees the elements of a Upload.
 *
 * @param _upload The Upload to free.
 */
static void freeNs0UploadType(struct drip_commons_ns0_upload *_upload);

#endif /* DEF_drip_commons_ns0_upload_H */
#ifndef DEF_drip_commons_ns0_attribute_M
#define DEF_drip_commons_ns0_attribute_M

/**
 * Reads a Attribute from XML. The reader is assumed to be at the start element.
 *
 * @return the Attribute, or NULL in case of error.
 */
static struct drip_commons_ns0_attribute *xmlTextReaderReadNs0AttributeType(xmlTextReaderPtr reader) {
  int status, depth;
  void *_child_accessor;
  struct drip_commons_ns0_attribute *_attribute = calloc(1, sizeof(struct drip_commons_ns0_attribute));

  if (xmlTextReaderHasAttributes(reader)) {
    while (xmlTextReaderMoveToNextAttribute(reader)) {
      if ((xmlStrcmp(BAD_CAST "name", xmlTextReaderConstLocalName(reader)) == 0) && (xmlTextReaderConstNamespaceUri(reader) == NULL)) {
#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read type {http://www.w3.org/2001/XMLSchema}string from attribute {}name...\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
          //panic: unable to return the attribute value for some reason.
#if DEBUG_ENUNCIATE
          printf("Failed to read attribute {}name of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          freeNs0AttributeType(_attribute);
          free(_attribute);
          return NULL;
        }
        _attribute->name = ((xmlChar*)_child_accessor);
        continue;
      }
      if ((xmlStrcmp(BAD_CAST "level", xmlTextReaderConstLocalName(reader)) == 0) && (xmlTextReaderConstNamespaceUri(reader) == NULL)) {
#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read type {http://www.w3.org/2001/XMLSchema}string from attribute {}level...\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
          //panic: unable to return the attribute value for some reason.
#if DEBUG_ENUNCIATE
          printf("Failed to read attribute {}level of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          freeNs0AttributeType(_attribute);
          free(_attribute);
          return NULL;
        }
        _attribute->level = ((xmlChar*)_child_accessor);
        continue;
      }
    }

    status = xmlTextReaderMoveToElement(reader);
    if (status < 1) {
      //panic: unable to return to the element node.
#if DEBUG_ENUNCIATE
      printf("Unable to return to element node from attributes.\n");
#endif
      freeNs0AttributeType(_attribute);
      free(_attribute);
      return NULL;
    }
  }

  if (xmlTextReaderIsEmptyElement(reader) == 0) {
#if DEBUG_ENUNCIATE > 1
    printf("Attempting to read type {http://www.w3.org/2001/XMLSchema}string from element value...\n");
#endif
    _child_accessor = xmlTextReaderReadXsStringType(reader);
    if (_child_accessor == NULL) {
      //panic: unable to return the value for some reason.
#if DEBUG_ENUNCIATE
      printf("Failed to read value of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
      freeNs0AttributeType(_attribute);
      free(_attribute);
      return NULL;
    }
    _attribute->content = ((xmlChar*)_child_accessor);
  }
  else {
    _attribute->content = BAD_CAST "";
  }


  return _attribute;
}

/**
 * Writes a Attribute to XML.
 *
 * @param writer The XML writer.
 * @param _attribute The Attribute to write.
 * @return The total bytes written, or -1 on error;
 */
static int xmlTextWriterWriteNs0AttributeType(xmlTextWriterPtr writer, struct drip_commons_ns0_attribute *_attribute) {
  int status, totalBytes = 0, i;
  xmlChar *binaryData;

  if (_attribute->name != NULL) {
    status = xmlTextWriterStartAttributeNS(writer, NULL, BAD_CAST "name", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start attribute {}name. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for attribute {}name...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_attribute->name));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for attribute {}name. status: %i", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndAttribute(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end attribute {}name. status: %i", status);
#endif
      return status;
    }
    totalBytes += status;
  }

  if (_attribute->level != NULL) {
    status = xmlTextWriterStartAttributeNS(writer, NULL, BAD_CAST "level", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start attribute {}level. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for attribute {}level...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_attribute->level));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for attribute {}level. status: %i", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndAttribute(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end attribute {}level. status: %i", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_attribute->content != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element value...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_attribute->content));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element value. status: %i", status);
#endif
      return status;
    }
    totalBytes += status;
  }

  return totalBytes;
}

/**
 * Frees the elements of a Attribute.
 *
 * @param _attribute The Attribute to free.
 */
static void freeNs0AttributeType(struct drip_commons_ns0_attribute *_attribute) {
  int i;
  if (_attribute->name != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor name of type drip_commons_ns0_attribute...\n");
#endif
    freeXsStringType(_attribute->name);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor name of type drip_commons_ns0_attribute...\n");
#endif
    free(_attribute->name);
  }
  if (_attribute->level != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor level of type drip_commons_ns0_attribute...\n");
#endif
    freeXsStringType(_attribute->level);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor level of type drip_commons_ns0_attribute...\n");
#endif
    free(_attribute->level);
  }
  if (_attribute->content != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor content of type drip_commons_ns0_attribute...\n");
#endif
    freeXsStringType(_attribute->content);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor content of type drip_commons_ns0_attribute...\n");
#endif
    free(_attribute->content);
  }
}
#endif /* DEF_drip_commons_ns0_attribute_M */
#ifndef DEF_drip_commons_ns0_confScript_M
#define DEF_drip_commons_ns0_confScript_M

/**
 * Reads a ConfScript element from XML. The element to be read is "confScript", and
 * it is assumed that the reader is pointing to the XML document (not the element).
 *
 * @param reader The XML reader.
 * @return The ConfScript, or NULL in case of error.
 */
struct drip_commons_ns0_confScript *xml_read_drip_commons_ns0_confScript(xmlTextReaderPtr reader) {
  int status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
  return xmlTextReaderReadNs0ConfScriptElement(reader);
}

/**
 * Writes a ConfScript to XML under element name "confScript".
 *
 * @param writer The XML writer.
 * @param _confScript The ConfScript to write.
 * @return 1 if successful, 0 otherwise.
 */
int xml_write_drip_commons_ns0_confScript(xmlTextWriterPtr writer, struct drip_commons_ns0_confScript *_confScript) {
  return xmlTextWriterWriteNs0ConfScriptElementNS(writer, _confScript, 1);
}

/**
 * Frees a ConfScript.
 *
 * @param _confScript The ConfScript to free.
 */
void free_drip_commons_ns0_confScript(struct drip_commons_ns0_confScript *_confScript) {
  freeNs0ConfScriptType(_confScript);
  free(_confScript);
}

/**
 * Reads a ConfScript element from XML. The element to be read is "confScript", and
 * it is assumed that the reader is pointing to that element.
 *
 * @param reader The XML reader.
 * @return The ConfScript, or NULL in case of error.
 */
struct drip_commons_ns0_confScript *xmlTextReaderReadNs0ConfScriptElement(xmlTextReaderPtr reader) {
  struct drip_commons_ns0_confScript *_confScript = NULL;

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "confScript", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Attempting to read root element {}confScript.\n");
#endif
    _confScript = xmlTextReaderReadNs0ConfScriptType(reader);
  }
#if DEBUG_ENUNCIATE
  if (_confScript == NULL) {
    if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
      printf("attempt to read {}confScript failed. current element: {}%s\n",  xmlTextReaderConstLocalName(reader));
    }
    else {
      printf("attempt to read {}confScript failed. current element: {%s}%s\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader));
    }
  }
#endif

  return _confScript;
}

/**
 * Writes a ConfScript to XML under element name "confScript".
 * Does NOT write the namespace prefixes.
 *
 * @param writer The XML writer.
 * @param _confScript The ConfScript to write.
 * @return 1 if successful, 0 otherwise.
 */
static int xmlTextWriterWriteNs0ConfScriptElement(xmlTextWriterPtr writer, struct drip_commons_ns0_confScript *_confScript) {
  return xmlTextWriterWriteNs0ConfScriptElementNS(writer, _confScript, 0);
}

/**
 * Writes a ConfScript to XML under element name "confScript".
 *
 * @param writer The XML writer.
 * @param _confScript The ConfScript to write.
 * @param writeNamespaces Whether to write the namespace prefixes.
 * @return 1 if successful, 0 otherwise.
 */
static int xmlTextWriterWriteNs0ConfScriptElementNS(xmlTextWriterPtr writer, struct drip_commons_ns0_confScript *_confScript, int writeNamespaces) {
  int totalBytes = 0;
  int status;

  status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "confScript", NULL);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to write start element {}confScript. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

#if DEBUG_ENUNCIATE > 1
  printf("writing type {}confScript for root element {}confScript...\n");
#endif
  status = xmlTextWriterWriteNs0ConfScriptType(writer, _confScript);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to write type for start element {}confScript. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

  status = xmlTextWriterEndElement(writer);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to end element {}confScript. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

  return totalBytes;
}

/**
 * Frees the children of a ConfScript.
 *
 * @param _confScript The ConfScript whose children are to be free.
 */
static void freeNs0ConfScriptElement(struct drip_commons_ns0_confScript *_confScript) {
  freeNs0ConfScriptType(_confScript);
}

/**
 * Reads a ConfScript from XML. The reader is assumed to be at the start element.
 *
 * @return the ConfScript, or NULL in case of error.
 */
static struct drip_commons_ns0_confScript *xmlTextReaderReadNs0ConfScriptType(xmlTextReaderPtr reader) {
  int status, depth;
  void *_child_accessor;
  struct drip_commons_ns0_confScript *_confScript = calloc(1, sizeof(struct drip_commons_ns0_confScript));



  if (xmlTextReaderIsEmptyElement(reader) == 0) {
    depth = xmlTextReaderDepth(reader);//track the depth.
    status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);

    while (xmlTextReaderDepth(reader) > depth) {
      if (status < 1) {
        //panic: XML read error.
#if DEBUG_ENUNCIATE
        printf("Failure to advance to next child element.\n");
#endif
        freeNs0ConfScriptType(_confScript);
        free(_confScript);
        return NULL;
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "user", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ConfScriptType(_confScript);
          free(_confScript);
          return NULL;
        }

        _confScript->user = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "pwd", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ConfScriptType(_confScript);
          free(_confScript);
          return NULL;
        }

        _confScript->pwd = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "action", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}action of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}action of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ConfScriptType(_confScript);
          free(_confScript);
          return NULL;
        }

        _confScript->action = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "script", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}script of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}script of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ConfScriptType(_confScript);
          free(_confScript);
          return NULL;
        }

        _confScript->script = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else {
#if DEBUG_ENUNCIATE > 1
        if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
          printf("unknown child element {}%s for type {}confScript.  Skipping...\n",  xmlTextReaderConstLocalName(reader));
        }
        else {
          printf("unknown child element {%s}%s for type {}confScript. Skipping...\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader));
        }
#endif
        status = xmlTextReaderSkipElement(reader);
      }
    }
  }

  return _confScript;
}

/**
 * Writes a ConfScript to XML.
 *
 * @param writer The XML writer.
 * @param _confScript The ConfScript to write.
 * @return The total bytes written, or -1 on error;
 */
static int xmlTextWriterWriteNs0ConfScriptType(xmlTextWriterPtr writer, struct drip_commons_ns0_confScript *_confScript) {
  int status, totalBytes = 0, i;
  xmlChar *binaryData;
  if (_confScript->user != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "user", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}user...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_confScript->user));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_confScript->pwd != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "pwd", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}pwd...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_confScript->pwd));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_confScript->action != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "action", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}action. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}action...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_confScript->action));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}action. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}action. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_confScript->script != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "script", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}script. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}script...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_confScript->script));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}script. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}script. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }

  return totalBytes;
}

/**
 * Frees the elements of a ConfScript.
 *
 * @param _confScript The ConfScript to free.
 */
static void freeNs0ConfScriptType(struct drip_commons_ns0_confScript *_confScript) {
  int i;
  if (_confScript->user != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor user of type drip_commons_ns0_confScript...\n");
#endif
    freeXsStringType(_confScript->user);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor user of type drip_commons_ns0_confScript...\n");
#endif
    free(_confScript->user);
  }
  if (_confScript->pwd != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor pwd of type drip_commons_ns0_confScript...\n");
#endif
    freeXsStringType(_confScript->pwd);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor pwd of type drip_commons_ns0_confScript...\n");
#endif
    free(_confScript->pwd);
  }
  if (_confScript->action != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor action of type drip_commons_ns0_confScript...\n");
#endif
    freeXsStringType(_confScript->action);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor action of type drip_commons_ns0_confScript...\n");
#endif
    free(_confScript->action);
  }
  if (_confScript->script != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor script of type drip_commons_ns0_confScript...\n");
#endif
    freeXsStringType(_confScript->script);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor script of type drip_commons_ns0_confScript...\n");
#endif
    free(_confScript->script);
  }
}
#endif /* DEF_drip_commons_ns0_confScript_M */
#ifndef DEF_drip_commons_ns0_confUserKey_M
#define DEF_drip_commons_ns0_confUserKey_M

/**
 * Reads a ConfUserKey element from XML. The element to be read is "confUserKey", and
 * it is assumed that the reader is pointing to the XML document (not the element).
 *
 * @param reader The XML reader.
 * @return The ConfUserKey, or NULL in case of error.
 */
struct drip_commons_ns0_confUserKey *xml_read_drip_commons_ns0_confUserKey(xmlTextReaderPtr reader) {
  int status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
  return xmlTextReaderReadNs0ConfUserKeyElement(reader);
}

/**
 * Writes a ConfUserKey to XML under element name "confUserKey".
 *
 * @param writer The XML writer.
 * @param _confUserKey The ConfUserKey to write.
 * @return 1 if successful, 0 otherwise.
 */
int xml_write_drip_commons_ns0_confUserKey(xmlTextWriterPtr writer, struct drip_commons_ns0_confUserKey *_confUserKey) {
  return xmlTextWriterWriteNs0ConfUserKeyElementNS(writer, _confUserKey, 1);
}

/**
 * Frees a ConfUserKey.
 *
 * @param _confUserKey The ConfUserKey to free.
 */
void free_drip_commons_ns0_confUserKey(struct drip_commons_ns0_confUserKey *_confUserKey) {
  freeNs0ConfUserKeyType(_confUserKey);
  free(_confUserKey);
}

/**
 * Reads a ConfUserKey element from XML. The element to be read is "confUserKey", and
 * it is assumed that the reader is pointing to that element.
 *
 * @param reader The XML reader.
 * @return The ConfUserKey, or NULL in case of error.
 */
struct drip_commons_ns0_confUserKey *xmlTextReaderReadNs0ConfUserKeyElement(xmlTextReaderPtr reader) {
  struct drip_commons_ns0_confUserKey *_confUserKey = NULL;

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "confUserKey", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Attempting to read root element {}confUserKey.\n");
#endif
    _confUserKey = xmlTextReaderReadNs0ConfUserKeyType(reader);
  }
#if DEBUG_ENUNCIATE
  if (_confUserKey == NULL) {
    if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
      printf("attempt to read {}confUserKey failed. current element: {}%s\n",  xmlTextReaderConstLocalName(reader));
    }
    else {
      printf("attempt to read {}confUserKey failed. current element: {%s}%s\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader));
    }
  }
#endif

  return _confUserKey;
}

/**
 * Writes a ConfUserKey to XML under element name "confUserKey".
 * Does NOT write the namespace prefixes.
 *
 * @param writer The XML writer.
 * @param _confUserKey The ConfUserKey to write.
 * @return 1 if successful, 0 otherwise.
 */
static int xmlTextWriterWriteNs0ConfUserKeyElement(xmlTextWriterPtr writer, struct drip_commons_ns0_confUserKey *_confUserKey) {
  return xmlTextWriterWriteNs0ConfUserKeyElementNS(writer, _confUserKey, 0);
}

/**
 * Writes a ConfUserKey to XML under element name "confUserKey".
 *
 * @param writer The XML writer.
 * @param _confUserKey The ConfUserKey to write.
 * @param writeNamespaces Whether to write the namespace prefixes.
 * @return 1 if successful, 0 otherwise.
 */
static int xmlTextWriterWriteNs0ConfUserKeyElementNS(xmlTextWriterPtr writer, struct drip_commons_ns0_confUserKey *_confUserKey, int writeNamespaces) {
  int totalBytes = 0;
  int status;

  status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "confUserKey", NULL);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to write start element {}confUserKey. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

#if DEBUG_ENUNCIATE > 1
  printf("writing type {}confUserKey for root element {}confUserKey...\n");
#endif
  status = xmlTextWriterWriteNs0ConfUserKeyType(writer, _confUserKey);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to write type for start element {}confUserKey. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

  status = xmlTextWriterEndElement(writer);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to end element {}confUserKey. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

  return totalBytes;
}

/**
 * Frees the children of a ConfUserKey.
 *
 * @param _confUserKey The ConfUserKey whose children are to be free.
 */
static void freeNs0ConfUserKeyElement(struct drip_commons_ns0_confUserKey *_confUserKey) {
  freeNs0ConfUserKeyType(_confUserKey);
}

/**
 * Reads a ConfUserKey from XML. The reader is assumed to be at the start element.
 *
 * @return the ConfUserKey, or NULL in case of error.
 */
static struct drip_commons_ns0_confUserKey *xmlTextReaderReadNs0ConfUserKeyType(xmlTextReaderPtr reader) {
  int status, depth;
  void *_child_accessor;
  struct drip_commons_ns0_confUserKey *_confUserKey = calloc(1, sizeof(struct drip_commons_ns0_confUserKey));



  if (xmlTextReaderIsEmptyElement(reader) == 0) {
    depth = xmlTextReaderDepth(reader);//track the depth.
    status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);

    while (xmlTextReaderDepth(reader) > depth) {
      if (status < 1) {
        //panic: XML read error.
#if DEBUG_ENUNCIATE
        printf("Failure to advance to next child element.\n");
#endif
        freeNs0ConfUserKeyType(_confUserKey);
        free(_confUserKey);
        return NULL;
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "user", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ConfUserKeyType(_confUserKey);
          free(_confUserKey);
          return NULL;
        }

        _confUserKey->user = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "pwd", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ConfUserKeyType(_confUserKey);
          free(_confUserKey);
          return NULL;
        }

        _confUserKey->pwd = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "action", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}action of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}action of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ConfUserKeyType(_confUserKey);
          free(_confUserKey);
          return NULL;
        }

        _confUserKey->action = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "userKey", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}userKey of type {}attribute.\n");
#endif
        _child_accessor = xmlTextReaderReadNs0AttributeType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}userKey of type {}attribute.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ConfUserKeyType(_confUserKey);
          free(_confUserKey);
          return NULL;
        }

        _confUserKey->file = realloc(_confUserKey->file, (_confUserKey->_sizeof_file + 1) * sizeof(struct drip_commons_ns0_attribute));
        memcpy(&(_confUserKey->file[_confUserKey->_sizeof_file++]), _child_accessor, sizeof(struct drip_commons_ns0_attribute));
        free(_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else {
#if DEBUG_ENUNCIATE > 1
        if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
          printf("unknown child element {}%s for type {}confUserKey.  Skipping...\n",  xmlTextReaderConstLocalName(reader));
        }
        else {
          printf("unknown child element {%s}%s for type {}confUserKey. Skipping...\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader));
        }
#endif
        status = xmlTextReaderSkipElement(reader);
      }
    }
  }

  return _confUserKey;
}

/**
 * Writes a ConfUserKey to XML.
 *
 * @param writer The XML writer.
 * @param _confUserKey The ConfUserKey to write.
 * @return The total bytes written, or -1 on error;
 */
static int xmlTextWriterWriteNs0ConfUserKeyType(xmlTextWriterPtr writer, struct drip_commons_ns0_confUserKey *_confUserKey) {
  int status, totalBytes = 0, i;
  xmlChar *binaryData;
  if (_confUserKey->user != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "user", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}user...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_confUserKey->user));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_confUserKey->pwd != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "pwd", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}pwd...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_confUserKey->pwd));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_confUserKey->action != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "action", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}action. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}action...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_confUserKey->action));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}action. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}action. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  for (i = 0; i < _confUserKey->_sizeof_file; i++) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "userKey", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}userKey. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {}attribute for element {}userKey...\n");
#endif
    status = xmlTextWriterWriteNs0AttributeType(writer, &(_confUserKey->file[i]));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {}attribute for element {}userKey. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}userKey. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }

  return totalBytes;
}

/**
 * Frees the elements of a ConfUserKey.
 *
 * @param _confUserKey The ConfUserKey to free.
 */
static void freeNs0ConfUserKeyType(struct drip_commons_ns0_confUserKey *_confUserKey) {
  int i;
  if (_confUserKey->user != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor user of type drip_commons_ns0_confUserKey...\n");
#endif
    freeXsStringType(_confUserKey->user);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor user of type drip_commons_ns0_confUserKey...\n");
#endif
    free(_confUserKey->user);
  }
  if (_confUserKey->pwd != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor pwd of type drip_commons_ns0_confUserKey...\n");
#endif
    freeXsStringType(_confUserKey->pwd);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor pwd of type drip_commons_ns0_confUserKey...\n");
#endif
    free(_confUserKey->pwd);
  }
  if (_confUserKey->action != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor action of type drip_commons_ns0_confUserKey...\n");
#endif
    freeXsStringType(_confUserKey->action);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor action of type drip_commons_ns0_confUserKey...\n");
#endif
    free(_confUserKey->action);
  }
  if (_confUserKey->file != NULL) {
    for (i = 0; i < _confUserKey->_sizeof_file; i++) {
#if DEBUG_ENUNCIATE > 1
      printf("Freeing accessor file[%i] of type drip_commons_ns0_confUserKey...\n", i);
#endif
      freeNs0AttributeType(&(_confUserKey->file[i]));
    }
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor file of type drip_commons_ns0_confUserKey...\n");
#endif
    free(_confUserKey->file);
  }
}
#endif /* DEF_drip_commons_ns0_confUserKey_M */
#ifndef DEF_drip_commons_ns0_configure_M
#define DEF_drip_commons_ns0_configure_M

/**
 * Reads a Configure element from XML. The element to be read is "configure", and
 * it is assumed that the reader is pointing to the XML document (not the element).
 *
 * @param reader The XML reader.
 * @return The Configure, or NULL in case of error.
 */
struct drip_commons_ns0_configure *xml_read_drip_commons_ns0_configure(xmlTextReaderPtr reader) {
  int status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
  return xmlTextReaderReadNs0ConfigureElement(reader);
}

/**
 * Writes a Configure to XML under element name "configure".
 *
 * @param writer The XML writer.
 * @param _configure The Configure to write.
 * @return 1 if successful, 0 otherwise.
 */
int xml_write_drip_commons_ns0_configure(xmlTextWriterPtr writer, struct drip_commons_ns0_configure *_configure) {
  return xmlTextWriterWriteNs0ConfigureElementNS(writer, _configure, 1);
}

/**
 * Frees a Configure.
 *
 * @param _configure The Configure to free.
 */
void free_drip_commons_ns0_configure(struct drip_commons_ns0_configure *_configure) {
  freeNs0ConfigureType(_configure);
  free(_configure);
}

/**
 * Reads a Configure element from XML. The element to be read is "configure", and
 * it is assumed that the reader is pointing to that element.
 *
 * @param reader The XML reader.
 * @return The Configure, or NULL in case of error.
 */
struct drip_commons_ns0_configure *xmlTextReaderReadNs0ConfigureElement(xmlTextReaderPtr reader) {
  struct drip_commons_ns0_configure *_configure = NULL;

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "configure", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Attempting to read root element {}configure.\n");
#endif
    _configure = xmlTextReaderReadNs0ConfigureType(reader);
  }
#if DEBUG_ENUNCIATE
  if (_configure == NULL) {
    if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
      printf("attempt to read {}configure failed. current element: {}%s\n",  xmlTextReaderConstLocalName(reader));
    }
    else {
      printf("attempt to read {}configure failed. current element: {%s}%s\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader));
    }
  }
#endif

  return _configure;
}

/**
 * Writes a Configure to XML under element name "configure".
 * Does NOT write the namespace prefixes.
 *
 * @param writer The XML writer.
 * @param _configure The Configure to write.
 * @return 1 if successful, 0 otherwise.
 */
static int xmlTextWriterWriteNs0ConfigureElement(xmlTextWriterPtr writer, struct drip_commons_ns0_configure *_configure) {
  return xmlTextWriterWriteNs0ConfigureElementNS(writer, _configure, 0);
}

/**
 * Writes a Configure to XML under element name "configure".
 *
 * @param writer The XML writer.
 * @param _configure The Configure to write.
 * @param writeNamespaces Whether to write the namespace prefixes.
 * @return 1 if successful, 0 otherwise.
 */
static int xmlTextWriterWriteNs0ConfigureElementNS(xmlTextWriterPtr writer, struct drip_commons_ns0_configure *_configure, int writeNamespaces) {
  int totalBytes = 0;
  int status;

  status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "configure", NULL);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to write start element {}configure. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

#if DEBUG_ENUNCIATE > 1
  printf("writing type {}configure for root element {}configure...\n");
#endif
  status = xmlTextWriterWriteNs0ConfigureType(writer, _configure);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to write type for start element {}configure. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

  status = xmlTextWriterEndElement(writer);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to end element {}configure. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

  return totalBytes;
}

/**
 * Frees the children of a Configure.
 *
 * @param _configure The Configure whose children are to be free.
 */
static void freeNs0ConfigureElement(struct drip_commons_ns0_configure *_configure) {
  freeNs0ConfigureType(_configure);
}

/**
 * Reads a Configure from XML. The reader is assumed to be at the start element.
 *
 * @return the Configure, or NULL in case of error.
 */
static struct drip_commons_ns0_configure *xmlTextReaderReadNs0ConfigureType(xmlTextReaderPtr reader) {
  int status, depth;
  void *_child_accessor;
  struct drip_commons_ns0_configure *_configure = calloc(1, sizeof(struct drip_commons_ns0_configure));



  if (xmlTextReaderIsEmptyElement(reader) == 0) {
    depth = xmlTextReaderDepth(reader);//track the depth.
    status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);

    while (xmlTextReaderDepth(reader) > depth) {
      if (status < 1) {
        //panic: XML read error.
#if DEBUG_ENUNCIATE
        printf("Failure to advance to next child element.\n");
#endif
        freeNs0ConfigureType(_configure);
        free(_configure);
        return NULL;
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "user", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ConfigureType(_configure);
          free(_configure);
          return NULL;
        }

        _configure->user = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "pwd", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ConfigureType(_configure);
          free(_configure);
          return NULL;
        }

        _configure->pwd = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "keyid", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}keyid of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}keyid of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ConfigureType(_configure);
          free(_configure);
          return NULL;
        }

        _configure->keyid = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "key", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}key of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}key of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ConfigureType(_configure);
          free(_configure);
          return NULL;
        }

        _configure->key = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "loginKey", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}loginKey of type {}loginKey0.\n");
#endif
        _child_accessor = xmlTextReaderReadNs0LoginKey0Type(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}loginKey of type {}loginKey0.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ConfigureType(_configure);
          free(_configure);
          return NULL;
        }

        _configure->loginKey = realloc(_configure->loginKey, (_configure->_sizeof_loginKey + 1) * sizeof(struct drip_commons_ns0_loginKey0));
        memcpy(&(_configure->loginKey[_configure->_sizeof_loginKey++]), _child_accessor, sizeof(struct drip_commons_ns0_loginKey0));
        free(_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "geniKey", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}geniKey of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}geniKey of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ConfigureType(_configure);
          free(_configure);
          return NULL;
        }

        _configure->geniKey = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "geniKeyAlias", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}geniKeyAlias of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}geniKeyAlias of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ConfigureType(_configure);
          free(_configure);
          return NULL;
        }

        _configure->geniKeyAlias = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "loginPubKey", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}loginPubKey of type {}loginKey0.\n");
#endif
        _child_accessor = xmlTextReaderReadNs0LoginKey0Type(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}loginPubKey of type {}loginKey0.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ConfigureType(_configure);
          free(_configure);
          return NULL;
        }

        _configure->loginPubKey = realloc(_configure->loginPubKey, (_configure->_sizeof_loginPubKey + 1) * sizeof(struct drip_commons_ns0_loginKey0));
        memcpy(&(_configure->loginPubKey[_configure->_sizeof_loginPubKey++]), _child_accessor, sizeof(struct drip_commons_ns0_loginKey0));
        free(_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "geniKeyPass", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}geniKeyPass of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}geniKeyPass of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ConfigureType(_configure);
          free(_configure);
          return NULL;
        }

        _configure->geniKeyPass = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "loginPriKey", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}loginPriKey of type {}loginKey0.\n");
#endif
        _child_accessor = xmlTextReaderReadNs0LoginKey0Type(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}loginPriKey of type {}loginKey0.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ConfigureType(_configure);
          free(_configure);
          return NULL;
        }

        _configure->loginPriKey = realloc(_configure->loginPriKey, (_configure->_sizeof_loginPriKey + 1) * sizeof(struct drip_commons_ns0_loginKey0));
        memcpy(&(_configure->loginPriKey[_configure->_sizeof_loginPriKey++]), _child_accessor, sizeof(struct drip_commons_ns0_loginKey0));
        free(_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else {
#if DEBUG_ENUNCIATE > 1
        if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
          printf("unknown child element {}%s for type {}configure.  Skipping...\n",  xmlTextReaderConstLocalName(reader));
        }
        else {
          printf("unknown child element {%s}%s for type {}configure. Skipping...\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader));
        }
#endif
        status = xmlTextReaderSkipElement(reader);
      }
    }
  }

  return _configure;
}

/**
 * Writes a Configure to XML.
 *
 * @param writer The XML writer.
 * @param _configure The Configure to write.
 * @return The total bytes written, or -1 on error;
 */
static int xmlTextWriterWriteNs0ConfigureType(xmlTextWriterPtr writer, struct drip_commons_ns0_configure *_configure) {
  int status, totalBytes = 0, i;
  xmlChar *binaryData;
  if (_configure->user != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "user", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}user...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_configure->user));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_configure->pwd != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "pwd", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}pwd...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_configure->pwd));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_configure->keyid != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "keyid", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}keyid. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}keyid...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_configure->keyid));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}keyid. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}keyid. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_configure->key != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "key", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}key. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}key...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_configure->key));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}key. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}key. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  for (i = 0; i < _configure->_sizeof_loginKey; i++) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "loginKey", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}loginKey. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {}loginKey0 for element {}loginKey...\n");
#endif
    status = xmlTextWriterWriteNs0LoginKey0Type(writer, &(_configure->loginKey[i]));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {}loginKey0 for element {}loginKey. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}loginKey. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_configure->geniKey != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "geniKey", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}geniKey. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}geniKey...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_configure->geniKey));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}geniKey. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}geniKey. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_configure->geniKeyAlias != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "geniKeyAlias", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}geniKeyAlias. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}geniKeyAlias...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_configure->geniKeyAlias));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}geniKeyAlias. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}geniKeyAlias. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  for (i = 0; i < _configure->_sizeof_loginPubKey; i++) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "loginPubKey", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}loginPubKey. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {}loginKey0 for element {}loginPubKey...\n");
#endif
    status = xmlTextWriterWriteNs0LoginKey0Type(writer, &(_configure->loginPubKey[i]));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {}loginKey0 for element {}loginPubKey. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}loginPubKey. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_configure->geniKeyPass != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "geniKeyPass", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}geniKeyPass. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}geniKeyPass...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_configure->geniKeyPass));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}geniKeyPass. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}geniKeyPass. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  for (i = 0; i < _configure->_sizeof_loginPriKey; i++) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "loginPriKey", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}loginPriKey. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {}loginKey0 for element {}loginPriKey...\n");
#endif
    status = xmlTextWriterWriteNs0LoginKey0Type(writer, &(_configure->loginPriKey[i]));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {}loginKey0 for element {}loginPriKey. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}loginPriKey. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }

  return totalBytes;
}

/**
 * Frees the elements of a Configure.
 *
 * @param _configure The Configure to free.
 */
static void freeNs0ConfigureType(struct drip_commons_ns0_configure *_configure) {
  int i;
  if (_configure->user != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor user of type drip_commons_ns0_configure...\n");
#endif
    freeXsStringType(_configure->user);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor user of type drip_commons_ns0_configure...\n");
#endif
    free(_configure->user);
  }
  if (_configure->pwd != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor pwd of type drip_commons_ns0_configure...\n");
#endif
    freeXsStringType(_configure->pwd);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor pwd of type drip_commons_ns0_configure...\n");
#endif
    free(_configure->pwd);
  }
  if (_configure->keyid != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor keyid of type drip_commons_ns0_configure...\n");
#endif
    freeXsStringType(_configure->keyid);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor keyid of type drip_commons_ns0_configure...\n");
#endif
    free(_configure->keyid);
  }
  if (_configure->key != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor key of type drip_commons_ns0_configure...\n");
#endif
    freeXsStringType(_configure->key);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor key of type drip_commons_ns0_configure...\n");
#endif
    free(_configure->key);
  }
  if (_configure->loginKey != NULL) {
    for (i = 0; i < _configure->_sizeof_loginKey; i++) {
#if DEBUG_ENUNCIATE > 1
      printf("Freeing accessor loginKey[%i] of type drip_commons_ns0_configure...\n", i);
#endif
      freeNs0LoginKey0Type(&(_configure->loginKey[i]));
    }
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor loginKey of type drip_commons_ns0_configure...\n");
#endif
    free(_configure->loginKey);
  }
  if (_configure->geniKey != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor geniKey of type drip_commons_ns0_configure...\n");
#endif
    freeXsStringType(_configure->geniKey);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor geniKey of type drip_commons_ns0_configure...\n");
#endif
    free(_configure->geniKey);
  }
  if (_configure->geniKeyAlias != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor geniKeyAlias of type drip_commons_ns0_configure...\n");
#endif
    freeXsStringType(_configure->geniKeyAlias);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor geniKeyAlias of type drip_commons_ns0_configure...\n");
#endif
    free(_configure->geniKeyAlias);
  }
  if (_configure->loginPubKey != NULL) {
    for (i = 0; i < _configure->_sizeof_loginPubKey; i++) {
#if DEBUG_ENUNCIATE > 1
      printf("Freeing accessor loginPubKey[%i] of type drip_commons_ns0_configure...\n", i);
#endif
      freeNs0LoginKey0Type(&(_configure->loginPubKey[i]));
    }
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor loginPubKey of type drip_commons_ns0_configure...\n");
#endif
    free(_configure->loginPubKey);
  }
  if (_configure->geniKeyPass != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor geniKeyPass of type drip_commons_ns0_configure...\n");
#endif
    freeXsStringType(_configure->geniKeyPass);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor geniKeyPass of type drip_commons_ns0_configure...\n");
#endif
    free(_configure->geniKeyPass);
  }
  if (_configure->loginPriKey != NULL) {
    for (i = 0; i < _configure->_sizeof_loginPriKey; i++) {
#if DEBUG_ENUNCIATE > 1
      printf("Freeing accessor loginPriKey[%i] of type drip_commons_ns0_configure...\n", i);
#endif
      freeNs0LoginKey0Type(&(_configure->loginPriKey[i]));
    }
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor loginPriKey of type drip_commons_ns0_configure...\n");
#endif
    free(_configure->loginPriKey);
  }
}
#endif /* DEF_drip_commons_ns0_configure_M */
#ifndef DEF_drip_commons_ns0_deploy_M
#define DEF_drip_commons_ns0_deploy_M

/**
 * Reads a Deploy element from XML. The element to be read is "deploy", and
 * it is assumed that the reader is pointing to the XML document (not the element).
 *
 * @param reader The XML reader.
 * @return The Deploy, or NULL in case of error.
 */
struct drip_commons_ns0_deploy *xml_read_drip_commons_ns0_deploy(xmlTextReaderPtr reader) {
  int status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
  return xmlTextReaderReadNs0DeployElement(reader);
}

/**
 * Writes a Deploy to XML under element name "deploy".
 *
 * @param writer The XML writer.
 * @param _deploy The Deploy to write.
 * @return 1 if successful, 0 otherwise.
 */
int xml_write_drip_commons_ns0_deploy(xmlTextWriterPtr writer, struct drip_commons_ns0_deploy *_deploy) {
  return xmlTextWriterWriteNs0DeployElementNS(writer, _deploy, 1);
}

/**
 * Frees a Deploy.
 *
 * @param _deploy The Deploy to free.
 */
void free_drip_commons_ns0_deploy(struct drip_commons_ns0_deploy *_deploy) {
  freeNs0DeployType(_deploy);
  free(_deploy);
}

/**
 * Reads a Deploy element from XML. The element to be read is "deploy", and
 * it is assumed that the reader is pointing to that element.
 *
 * @param reader The XML reader.
 * @return The Deploy, or NULL in case of error.
 */
struct drip_commons_ns0_deploy *xmlTextReaderReadNs0DeployElement(xmlTextReaderPtr reader) {
  struct drip_commons_ns0_deploy *_deploy = NULL;

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "deploy", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Attempting to read root element {}deploy.\n");
#endif
    _deploy = xmlTextReaderReadNs0DeployType(reader);
  }
#if DEBUG_ENUNCIATE
  if (_deploy == NULL) {
    if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
      printf("attempt to read {}deploy failed. current element: {}%s\n",  xmlTextReaderConstLocalName(reader));
    }
    else {
      printf("attempt to read {}deploy failed. current element: {%s}%s\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader));
    }
  }
#endif

  return _deploy;
}

/**
 * Writes a Deploy to XML under element name "deploy".
 * Does NOT write the namespace prefixes.
 *
 * @param writer The XML writer.
 * @param _deploy The Deploy to write.
 * @return 1 if successful, 0 otherwise.
 */
static int xmlTextWriterWriteNs0DeployElement(xmlTextWriterPtr writer, struct drip_commons_ns0_deploy *_deploy) {
  return xmlTextWriterWriteNs0DeployElementNS(writer, _deploy, 0);
}

/**
 * Writes a Deploy to XML under element name "deploy".
 *
 * @param writer The XML writer.
 * @param _deploy The Deploy to write.
 * @param writeNamespaces Whether to write the namespace prefixes.
 * @return 1 if successful, 0 otherwise.
 */
static int xmlTextWriterWriteNs0DeployElementNS(xmlTextWriterPtr writer, struct drip_commons_ns0_deploy *_deploy, int writeNamespaces) {
  int totalBytes = 0;
  int status;

  status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "deploy", NULL);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to write start element {}deploy. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

#if DEBUG_ENUNCIATE > 1
  printf("writing type {}deploy for root element {}deploy...\n");
#endif
  status = xmlTextWriterWriteNs0DeployType(writer, _deploy);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to write type for start element {}deploy. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

  status = xmlTextWriterEndElement(writer);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to end element {}deploy. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

  return totalBytes;
}

/**
 * Frees the children of a Deploy.
 *
 * @param _deploy The Deploy whose children are to be free.
 */
static void freeNs0DeployElement(struct drip_commons_ns0_deploy *_deploy) {
  freeNs0DeployType(_deploy);
}

/**
 * Reads a Deploy from XML. The reader is assumed to be at the start element.
 *
 * @return the Deploy, or NULL in case of error.
 */
static struct drip_commons_ns0_deploy *xmlTextReaderReadNs0DeployType(xmlTextReaderPtr reader) {
  int status, depth;
  void *_child_accessor;
  struct drip_commons_ns0_deploy *_deploy = calloc(1, sizeof(struct drip_commons_ns0_deploy));



  if (xmlTextReaderIsEmptyElement(reader) == 0) {
    depth = xmlTextReaderDepth(reader);//track the depth.
    status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);

    while (xmlTextReaderDepth(reader) > depth) {
      if (status < 1) {
        //panic: XML read error.
#if DEBUG_ENUNCIATE
        printf("Failure to advance to next child element.\n");
#endif
        freeNs0DeployType(_deploy);
        free(_deploy);
        return NULL;
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "user", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0DeployType(_deploy);
          free(_deploy);
          return NULL;
        }

        _deploy->user = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "pwd", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0DeployType(_deploy);
          free(_deploy);
          return NULL;
        }

        _deploy->pwd = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "action", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}action of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}action of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0DeployType(_deploy);
          free(_deploy);
          return NULL;
        }

        _deploy->action = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else {
#if DEBUG_ENUNCIATE > 1
        if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
          printf("unknown child element {}%s for type {}deploy.  Skipping...\n",  xmlTextReaderConstLocalName(reader));
        }
        else {
          printf("unknown child element {%s}%s for type {}deploy. Skipping...\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader));
        }
#endif
        status = xmlTextReaderSkipElement(reader);
      }
    }
  }

  return _deploy;
}

/**
 * Writes a Deploy to XML.
 *
 * @param writer The XML writer.
 * @param _deploy The Deploy to write.
 * @return The total bytes written, or -1 on error;
 */
static int xmlTextWriterWriteNs0DeployType(xmlTextWriterPtr writer, struct drip_commons_ns0_deploy *_deploy) {
  int status, totalBytes = 0, i;
  xmlChar *binaryData;
  if (_deploy->user != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "user", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}user...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_deploy->user));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_deploy->pwd != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "pwd", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}pwd...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_deploy->pwd));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_deploy->action != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "action", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}action. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}action...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_deploy->action));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}action. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}action. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }

  return totalBytes;
}

/**
 * Frees the elements of a Deploy.
 *
 * @param _deploy The Deploy to free.
 */
static void freeNs0DeployType(struct drip_commons_ns0_deploy *_deploy) {
  int i;
  if (_deploy->user != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor user of type drip_commons_ns0_deploy...\n");
#endif
    freeXsStringType(_deploy->user);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor user of type drip_commons_ns0_deploy...\n");
#endif
    free(_deploy->user);
  }
  if (_deploy->pwd != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor pwd of type drip_commons_ns0_deploy...\n");
#endif
    freeXsStringType(_deploy->pwd);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor pwd of type drip_commons_ns0_deploy...\n");
#endif
    free(_deploy->pwd);
  }
  if (_deploy->action != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor action of type drip_commons_ns0_deploy...\n");
#endif
    freeXsStringType(_deploy->action);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor action of type drip_commons_ns0_deploy...\n");
#endif
    free(_deploy->action);
  }
}
#endif /* DEF_drip_commons_ns0_deploy_M */
#ifndef DEF_drip_commons_ns0_execute_M
#define DEF_drip_commons_ns0_execute_M

/**
 * Reads a Execute element from XML. The element to be read is "execute", and
 * it is assumed that the reader is pointing to the XML document (not the element).
 *
 * @param reader The XML reader.
 * @return The Execute, or NULL in case of error.
 */
struct drip_commons_ns0_execute *xml_read_drip_commons_ns0_execute(xmlTextReaderPtr reader) {
  int status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
  return xmlTextReaderReadNs0ExecuteElement(reader);
}

/**
 * Writes a Execute to XML under element name "execute".
 *
 * @param writer The XML writer.
 * @param _execute The Execute to write.
 * @return 1 if successful, 0 otherwise.
 */
int xml_write_drip_commons_ns0_execute(xmlTextWriterPtr writer, struct drip_commons_ns0_execute *_execute) {
  return xmlTextWriterWriteNs0ExecuteElementNS(writer, _execute, 1);
}

/**
 * Frees a Execute.
 *
 * @param _execute The Execute to free.
 */
void free_drip_commons_ns0_execute(struct drip_commons_ns0_execute *_execute) {
  freeNs0ExecuteType(_execute);
  free(_execute);
}

/**
 * Reads a Execute element from XML. The element to be read is "execute", and
 * it is assumed that the reader is pointing to that element.
 *
 * @param reader The XML reader.
 * @return The Execute, or NULL in case of error.
 */
struct drip_commons_ns0_execute *xmlTextReaderReadNs0ExecuteElement(xmlTextReaderPtr reader) {
  struct drip_commons_ns0_execute *_execute = NULL;

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "execute", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Attempting to read root element {}execute.\n");
#endif
    _execute = xmlTextReaderReadNs0ExecuteType(reader);
  }
#if DEBUG_ENUNCIATE
  if (_execute == NULL) {
    if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
      printf("attempt to read {}execute failed. current element: {}%s\n",  xmlTextReaderConstLocalName(reader));
    }
    else {
      printf("attempt to read {}execute failed. current element: {%s}%s\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader));
    }
  }
#endif

  return _execute;
}

/**
 * Writes a Execute to XML under element name "execute".
 * Does NOT write the namespace prefixes.
 *
 * @param writer The XML writer.
 * @param _execute The Execute to write.
 * @return 1 if successful, 0 otherwise.
 */
static int xmlTextWriterWriteNs0ExecuteElement(xmlTextWriterPtr writer, struct drip_commons_ns0_execute *_execute) {
  return xmlTextWriterWriteNs0ExecuteElementNS(writer, _execute, 0);
}

/**
 * Writes a Execute to XML under element name "execute".
 *
 * @param writer The XML writer.
 * @param _execute The Execute to write.
 * @param writeNamespaces Whether to write the namespace prefixes.
 * @return 1 if successful, 0 otherwise.
 */
static int xmlTextWriterWriteNs0ExecuteElementNS(xmlTextWriterPtr writer, struct drip_commons_ns0_execute *_execute, int writeNamespaces) {
  int totalBytes = 0;
  int status;

  status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "execute", NULL);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to write start element {}execute. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

#if DEBUG_ENUNCIATE > 1
  printf("writing type {}execute for root element {}execute...\n");
#endif
  status = xmlTextWriterWriteNs0ExecuteType(writer, _execute);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to write type for start element {}execute. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

  status = xmlTextWriterEndElement(writer);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to end element {}execute. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

  return totalBytes;
}

/**
 * Frees the children of a Execute.
 *
 * @param _execute The Execute whose children are to be free.
 */
static void freeNs0ExecuteElement(struct drip_commons_ns0_execute *_execute) {
  freeNs0ExecuteType(_execute);
}

/**
 * Reads a Execute from XML. The reader is assumed to be at the start element.
 *
 * @return the Execute, or NULL in case of error.
 */
static struct drip_commons_ns0_execute *xmlTextReaderReadNs0ExecuteType(xmlTextReaderPtr reader) {
  int status, depth;
  void *_child_accessor;
  struct drip_commons_ns0_execute *_execute = calloc(1, sizeof(struct drip_commons_ns0_execute));



  if (xmlTextReaderIsEmptyElement(reader) == 0) {
    depth = xmlTextReaderDepth(reader);//track the depth.
    status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);

    while (xmlTextReaderDepth(reader) > depth) {
      if (status < 1) {
        //panic: XML read error.
#if DEBUG_ENUNCIATE
        printf("Failure to advance to next child element.\n");
#endif
        freeNs0ExecuteType(_execute);
        free(_execute);
        return NULL;
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "user", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ExecuteType(_execute);
          free(_execute);
          return NULL;
        }

        _execute->user = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "pwd", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ExecuteType(_execute);
          free(_execute);
          return NULL;
        }

        _execute->pwd = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "action", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}action of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}action of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ExecuteType(_execute);
          free(_execute);
          return NULL;
        }

        _execute->action = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else {
#if DEBUG_ENUNCIATE > 1
        if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
          printf("unknown child element {}%s for type {}execute.  Skipping...\n",  xmlTextReaderConstLocalName(reader));
        }
        else {
          printf("unknown child element {%s}%s for type {}execute. Skipping...\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader));
        }
#endif
        status = xmlTextReaderSkipElement(reader);
      }
    }
  }

  return _execute;
}

/**
 * Writes a Execute to XML.
 *
 * @param writer The XML writer.
 * @param _execute The Execute to write.
 * @return The total bytes written, or -1 on error;
 */
static int xmlTextWriterWriteNs0ExecuteType(xmlTextWriterPtr writer, struct drip_commons_ns0_execute *_execute) {
  int status, totalBytes = 0, i;
  xmlChar *binaryData;
  if (_execute->user != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "user", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}user...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_execute->user));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_execute->pwd != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "pwd", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}pwd...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_execute->pwd));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_execute->action != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "action", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}action. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}action...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_execute->action));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}action. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}action. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }

  return totalBytes;
}

/**
 * Frees the elements of a Execute.
 *
 * @param _execute The Execute to free.
 */
static void freeNs0ExecuteType(struct drip_commons_ns0_execute *_execute) {
  int i;
  if (_execute->user != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor user of type drip_commons_ns0_execute...\n");
#endif
    freeXsStringType(_execute->user);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor user of type drip_commons_ns0_execute...\n");
#endif
    free(_execute->user);
  }
  if (_execute->pwd != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor pwd of type drip_commons_ns0_execute...\n");
#endif
    freeXsStringType(_execute->pwd);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor pwd of type drip_commons_ns0_execute...\n");
#endif
    free(_execute->pwd);
  }
  if (_execute->action != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor action of type drip_commons_ns0_execute...\n");
#endif
    freeXsStringType(_execute->action);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor action of type drip_commons_ns0_execute...\n");
#endif
    free(_execute->action);
  }
}
#endif /* DEF_drip_commons_ns0_execute_M */
#ifndef DEF_drip_commons_ns0_loginKey0_M
#define DEF_drip_commons_ns0_loginKey0_M

/**
 * Reads a LoginKey0 from XML. The reader is assumed to be at the start element.
 *
 * @return the LoginKey0, or NULL in case of error.
 */
static struct drip_commons_ns0_loginKey0 *xmlTextReaderReadNs0LoginKey0Type(xmlTextReaderPtr reader) {
  int status, depth;
  void *_child_accessor;
  struct drip_commons_ns0_loginKey0 *_loginKey0 = calloc(1, sizeof(struct drip_commons_ns0_loginKey0));

  if (xmlTextReaderHasAttributes(reader)) {
    while (xmlTextReaderMoveToNextAttribute(reader)) {
      if ((xmlStrcmp(BAD_CAST "domain_name", xmlTextReaderConstLocalName(reader)) == 0) && (xmlTextReaderConstNamespaceUri(reader) == NULL)) {
#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read type {http://www.w3.org/2001/XMLSchema}string from attribute {}domain_name...\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
          //panic: unable to return the attribute value for some reason.
#if DEBUG_ENUNCIATE
          printf("Failed to read attribute {}domain_name of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          freeNs0LoginKey0Type(_loginKey0);
          free(_loginKey0);
          return NULL;
        }
        _loginKey0->domain_name = ((xmlChar*)_child_accessor);
        continue;
      }
    }

    status = xmlTextReaderMoveToElement(reader);
    if (status < 1) {
      //panic: unable to return to the element node.
#if DEBUG_ENUNCIATE
      printf("Unable to return to element node from attributes.\n");
#endif
      freeNs0LoginKey0Type(_loginKey0);
      free(_loginKey0);
      return NULL;
    }
  }

  if (xmlTextReaderIsEmptyElement(reader) == 0) {
#if DEBUG_ENUNCIATE > 1
    printf("Attempting to read type {http://www.w3.org/2001/XMLSchema}string from element value...\n");
#endif
    _child_accessor = xmlTextReaderReadXsStringType(reader);
    if (_child_accessor == NULL) {
      //panic: unable to return the value for some reason.
#if DEBUG_ENUNCIATE
      printf("Failed to read value of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
      freeNs0LoginKey0Type(_loginKey0);
      free(_loginKey0);
      return NULL;
    }
    _loginKey0->content = ((xmlChar*)_child_accessor);
  }
  else {
    _loginKey0->content = BAD_CAST "";
  }


  return _loginKey0;
}

/**
 * Writes a LoginKey0 to XML.
 *
 * @param writer The XML writer.
 * @param _loginKey0 The LoginKey0 to write.
 * @return The total bytes written, or -1 on error;
 */
static int xmlTextWriterWriteNs0LoginKey0Type(xmlTextWriterPtr writer, struct drip_commons_ns0_loginKey0 *_loginKey0) {
  int status, totalBytes = 0, i;
  xmlChar *binaryData;

  if (_loginKey0->domain_name != NULL) {
    status = xmlTextWriterStartAttributeNS(writer, NULL, BAD_CAST "domain_name", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start attribute {}domain_name. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for attribute {}domain_name...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_loginKey0->domain_name));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for attribute {}domain_name. status: %i", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndAttribute(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end attribute {}domain_name. status: %i", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_loginKey0->content != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element value...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_loginKey0->content));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element value. status: %i", status);
#endif
      return status;
    }
    totalBytes += status;
  }

  return totalBytes;
}

/**
 * Frees the elements of a LoginKey0.
 *
 * @param _loginKey0 The LoginKey0 to free.
 */
static void freeNs0LoginKey0Type(struct drip_commons_ns0_loginKey0 *_loginKey0) {
  int i;
  if (_loginKey0->domain_name != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor domain_name of type drip_commons_ns0_loginKey0...\n");
#endif
    freeXsStringType(_loginKey0->domain_name);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor domain_name of type drip_commons_ns0_loginKey0...\n");
#endif
    free(_loginKey0->domain_name);
  }
  if (_loginKey0->content != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor content of type drip_commons_ns0_loginKey0...\n");
#endif
    freeXsStringType(_loginKey0->content);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor content of type drip_commons_ns0_loginKey0...\n");
#endif
    free(_loginKey0->content);
  }
}
#endif /* DEF_drip_commons_ns0_loginKey0_M */
#ifndef DEF_drip_commons_ns0_plan_M
#define DEF_drip_commons_ns0_plan_M

/**
 * Reads a Plan element from XML. The element to be read is "plan", and
 * it is assumed that the reader is pointing to the XML document (not the element).
 *
 * @param reader The XML reader.
 * @return The Plan, or NULL in case of error.
 */
struct drip_commons_ns0_plan *xml_read_drip_commons_ns0_plan(xmlTextReaderPtr reader) {
  int status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
  return xmlTextReaderReadNs0PlanElement(reader);
}

/**
 * Writes a Plan to XML under element name "plan".
 *
 * @param writer The XML writer.
 * @param _plan The Plan to write.
 * @return 1 if successful, 0 otherwise.
 */
int xml_write_drip_commons_ns0_plan(xmlTextWriterPtr writer, struct drip_commons_ns0_plan *_plan) {
  return xmlTextWriterWriteNs0PlanElementNS(writer, _plan, 1);
}

/**
 * Frees a Plan.
 *
 * @param _plan The Plan to free.
 */
void free_drip_commons_ns0_plan(struct drip_commons_ns0_plan *_plan) {
  freeNs0PlanType(_plan);
  free(_plan);
}

/**
 * Reads a Plan element from XML. The element to be read is "plan", and
 * it is assumed that the reader is pointing to that element.
 *
 * @param reader The XML reader.
 * @return The Plan, or NULL in case of error.
 */
struct drip_commons_ns0_plan *xmlTextReaderReadNs0PlanElement(xmlTextReaderPtr reader) {
  struct drip_commons_ns0_plan *_plan = NULL;

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "plan", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Attempting to read root element {}plan.\n");
#endif
    _plan = xmlTextReaderReadNs0PlanType(reader);
  }
#if DEBUG_ENUNCIATE
  if (_plan == NULL) {
    if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
      printf("attempt to read {}plan failed. current element: {}%s\n",  xmlTextReaderConstLocalName(reader));
    }
    else {
      printf("attempt to read {}plan failed. current element: {%s}%s\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader));
    }
  }
#endif

  return _plan;
}

/**
 * Writes a Plan to XML under element name "plan".
 * Does NOT write the namespace prefixes.
 *
 * @param writer The XML writer.
 * @param _plan The Plan to write.
 * @return 1 if successful, 0 otherwise.
 */
static int xmlTextWriterWriteNs0PlanElement(xmlTextWriterPtr writer, struct drip_commons_ns0_plan *_plan) {
  return xmlTextWriterWriteNs0PlanElementNS(writer, _plan, 0);
}

/**
 * Writes a Plan to XML under element name "plan".
 *
 * @param writer The XML writer.
 * @param _plan The Plan to write.
 * @param writeNamespaces Whether to write the namespace prefixes.
 * @return 1 if successful, 0 otherwise.
 */
static int xmlTextWriterWriteNs0PlanElementNS(xmlTextWriterPtr writer, struct drip_commons_ns0_plan *_plan, int writeNamespaces) {
  int totalBytes = 0;
  int status;

  status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "plan", NULL);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to write start element {}plan. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

#if DEBUG_ENUNCIATE > 1
  printf("writing type {}plan for root element {}plan...\n");
#endif
  status = xmlTextWriterWriteNs0PlanType(writer, _plan);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to write type for start element {}plan. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

  status = xmlTextWriterEndElement(writer);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to end element {}plan. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

  return totalBytes;
}

/**
 * Frees the children of a Plan.
 *
 * @param _plan The Plan whose children are to be free.
 */
static void freeNs0PlanElement(struct drip_commons_ns0_plan *_plan) {
  freeNs0PlanType(_plan);
}

/**
 * Reads a Plan from XML. The reader is assumed to be at the start element.
 *
 * @return the Plan, or NULL in case of error.
 */
static struct drip_commons_ns0_plan *xmlTextReaderReadNs0PlanType(xmlTextReaderPtr reader) {
  int status, depth;
  void *_child_accessor;
  struct drip_commons_ns0_plan *_plan = calloc(1, sizeof(struct drip_commons_ns0_plan));



  if (xmlTextReaderIsEmptyElement(reader) == 0) {
    depth = xmlTextReaderDepth(reader);//track the depth.
    status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);

    while (xmlTextReaderDepth(reader) > depth) {
      if (status < 1) {
        //panic: XML read error.
#if DEBUG_ENUNCIATE
        printf("Failure to advance to next child element.\n");
#endif
        freeNs0PlanType(_plan);
        free(_plan);
        return NULL;
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "user", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0PlanType(_plan);
          free(_plan);
          return NULL;
        }

        _plan->user = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "pwd", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0PlanType(_plan);
          free(_plan);
          return NULL;
        }

        _plan->pwd = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "file", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}file of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}file of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0PlanType(_plan);
          free(_plan);
          return NULL;
        }

        _plan->file = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else {
#if DEBUG_ENUNCIATE > 1
        if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
          printf("unknown child element {}%s for type {}plan.  Skipping...\n",  xmlTextReaderConstLocalName(reader));
        }
        else {
          printf("unknown child element {%s}%s for type {}plan. Skipping...\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader));
        }
#endif
        status = xmlTextReaderSkipElement(reader);
      }
    }
  }

  return _plan;
}

/**
 * Writes a Plan to XML.
 *
 * @param writer The XML writer.
 * @param _plan The Plan to write.
 * @return The total bytes written, or -1 on error;
 */
static int xmlTextWriterWriteNs0PlanType(xmlTextWriterPtr writer, struct drip_commons_ns0_plan *_plan) {
  int status, totalBytes = 0, i;
  xmlChar *binaryData;
  if (_plan->user != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "user", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}user...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_plan->user));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_plan->pwd != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "pwd", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}pwd...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_plan->pwd));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_plan->file != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "file", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}file. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}file...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_plan->file));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}file. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}file. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }

  return totalBytes;
}

/**
 * Frees the elements of a Plan.
 *
 * @param _plan The Plan to free.
 */
static void freeNs0PlanType(struct drip_commons_ns0_plan *_plan) {
  int i;
  if (_plan->user != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor user of type drip_commons_ns0_plan...\n");
#endif
    freeXsStringType(_plan->user);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor user of type drip_commons_ns0_plan...\n");
#endif
    free(_plan->user);
  }
  if (_plan->pwd != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor pwd of type drip_commons_ns0_plan...\n");
#endif
    freeXsStringType(_plan->pwd);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor pwd of type drip_commons_ns0_plan...\n");
#endif
    free(_plan->pwd);
  }
  if (_plan->file != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor file of type drip_commons_ns0_plan...\n");
#endif
    freeXsStringType(_plan->file);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor file of type drip_commons_ns0_plan...\n");
#endif
    free(_plan->file);
  }
}
#endif /* DEF_drip_commons_ns0_plan_M */
#ifndef DEF_drip_commons_ns0_register_M
#define DEF_drip_commons_ns0_register_M

/**
 * Reads a Register element from XML. The element to be read is "register", and
 * it is assumed that the reader is pointing to the XML document (not the element).
 *
 * @param reader The XML reader.
 * @return The Register, or NULL in case of error.
 */
struct drip_commons_ns0_register *xml_read_drip_commons_ns0_register(xmlTextReaderPtr reader) {
  int status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
  return xmlTextReaderReadNs0RegisterElement(reader);
}

/**
 * Writes a Register to XML under element name "register".
 *
 * @param writer The XML writer.
 * @param _register The Register to write.
 * @return 1 if successful, 0 otherwise.
 */
int xml_write_drip_commons_ns0_register(xmlTextWriterPtr writer, struct drip_commons_ns0_register *_register) {
  return xmlTextWriterWriteNs0RegisterElementNS(writer, _register, 1);
}

/**
 * Frees a Register.
 *
 * @param _register The Register to free.
 */
void free_drip_commons_ns0_register(struct drip_commons_ns0_register *_register) {
  freeNs0RegisterType(_register);
  free(_register);
}

/**
 * Reads a Register element from XML. The element to be read is "register", and
 * it is assumed that the reader is pointing to that element.
 *
 * @param reader The XML reader.
 * @return The Register, or NULL in case of error.
 */
struct drip_commons_ns0_register *xmlTextReaderReadNs0RegisterElement(xmlTextReaderPtr reader) {
  struct drip_commons_ns0_register *_register = NULL;

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "register", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Attempting to read root element {}register.\n");
#endif
    _register = xmlTextReaderReadNs0RegisterType(reader);
  }
#if DEBUG_ENUNCIATE
  if (_register == NULL) {
    if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
      printf("attempt to read {}register failed. current element: {}%s\n",  xmlTextReaderConstLocalName(reader));
    }
    else {
      printf("attempt to read {}register failed. current element: {%s}%s\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader));
    }
  }
#endif

  return _register;
}

/**
 * Writes a Register to XML under element name "register".
 * Does NOT write the namespace prefixes.
 *
 * @param writer The XML writer.
 * @param _register The Register to write.
 * @return 1 if successful, 0 otherwise.
 */
static int xmlTextWriterWriteNs0RegisterElement(xmlTextWriterPtr writer, struct drip_commons_ns0_register *_register) {
  return xmlTextWriterWriteNs0RegisterElementNS(writer, _register, 0);
}

/**
 * Writes a Register to XML under element name "register".
 *
 * @param writer The XML writer.
 * @param _register The Register to write.
 * @param writeNamespaces Whether to write the namespace prefixes.
 * @return 1 if successful, 0 otherwise.
 */
static int xmlTextWriterWriteNs0RegisterElementNS(xmlTextWriterPtr writer, struct drip_commons_ns0_register *_register, int writeNamespaces) {
  int totalBytes = 0;
  int status;

  status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "register", NULL);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to write start element {}register. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

#if DEBUG_ENUNCIATE > 1
  printf("writing type {}register for root element {}register...\n");
#endif
  status = xmlTextWriterWriteNs0RegisterType(writer, _register);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to write type for start element {}register. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

  status = xmlTextWriterEndElement(writer);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to end element {}register. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

  return totalBytes;
}

/**
 * Frees the children of a Register.
 *
 * @param _register The Register whose children are to be free.
 */
static void freeNs0RegisterElement(struct drip_commons_ns0_register *_register) {
  freeNs0RegisterType(_register);
}

/**
 * Reads a Register from XML. The reader is assumed to be at the start element.
 *
 * @return the Register, or NULL in case of error.
 */
static struct drip_commons_ns0_register *xmlTextReaderReadNs0RegisterType(xmlTextReaderPtr reader) {
  int status, depth;
  void *_child_accessor;
  struct drip_commons_ns0_register *_register = calloc(1, sizeof(struct drip_commons_ns0_register));



  if (xmlTextReaderIsEmptyElement(reader) == 0) {
    depth = xmlTextReaderDepth(reader);//track the depth.
    status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);

    while (xmlTextReaderDepth(reader) > depth) {
      if (status < 1) {
        //panic: XML read error.
#if DEBUG_ENUNCIATE
        printf("Failure to advance to next child element.\n");
#endif
        freeNs0RegisterType(_register);
        free(_register);
        return NULL;
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "user", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0RegisterType(_register);
          free(_register);
          return NULL;
        }

        _register->user = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "pwd", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0RegisterType(_register);
          free(_register);
          return NULL;
        }

        _register->pwd = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else {
#if DEBUG_ENUNCIATE > 1
        if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
          printf("unknown child element {}%s for type {}register.  Skipping...\n",  xmlTextReaderConstLocalName(reader));
        }
        else {
          printf("unknown child element {%s}%s for type {}register. Skipping...\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader));
        }
#endif
        status = xmlTextReaderSkipElement(reader);
      }
    }
  }

  return _register;
}

/**
 * Writes a Register to XML.
 *
 * @param writer The XML writer.
 * @param _register The Register to write.
 * @return The total bytes written, or -1 on error;
 */
static int xmlTextWriterWriteNs0RegisterType(xmlTextWriterPtr writer, struct drip_commons_ns0_register *_register) {
  int status, totalBytes = 0, i;
  xmlChar *binaryData;
  if (_register->user != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "user", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}user...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_register->user));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_register->pwd != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "pwd", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}pwd...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_register->pwd));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }

  return totalBytes;
}

/**
 * Frees the elements of a Register.
 *
 * @param _register The Register to free.
 */
static void freeNs0RegisterType(struct drip_commons_ns0_register *_register) {
  int i;
  if (_register->user != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor user of type drip_commons_ns0_register...\n");
#endif
    freeXsStringType(_register->user);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor user of type drip_commons_ns0_register...\n");
#endif
    free(_register->user);
  }
  if (_register->pwd != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor pwd of type drip_commons_ns0_register...\n");
#endif
    freeXsStringType(_register->pwd);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor pwd of type drip_commons_ns0_register...\n");
#endif
    free(_register->pwd);
  }
}
#endif /* DEF_drip_commons_ns0_register_M */
#ifndef DEF_drip_commons_ns0_result_M
#define DEF_drip_commons_ns0_result_M

/**
 * Reads a Result element from XML. The element to be read is "result", and
 * it is assumed that the reader is pointing to the XML document (not the element).
 *
 * @param reader The XML reader.
 * @return The Result, or NULL in case of error.
 */
struct drip_commons_ns0_result *xml_read_drip_commons_ns0_result(xmlTextReaderPtr reader) {
  int status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
  return xmlTextReaderReadNs0ResultElement(reader);
}

/**
 * Writes a Result to XML under element name "result".
 *
 * @param writer The XML writer.
 * @param _result The Result to write.
 * @return 1 if successful, 0 otherwise.
 */
int xml_write_drip_commons_ns0_result(xmlTextWriterPtr writer, struct drip_commons_ns0_result *_result) {
  return xmlTextWriterWriteNs0ResultElementNS(writer, _result, 1);
}

/**
 * Frees a Result.
 *
 * @param _result The Result to free.
 */
void free_drip_commons_ns0_result(struct drip_commons_ns0_result *_result) {
  freeNs0ResultType(_result);
  free(_result);
}

/**
 * Reads a Result element from XML. The element to be read is "result", and
 * it is assumed that the reader is pointing to that element.
 *
 * @param reader The XML reader.
 * @return The Result, or NULL in case of error.
 */
struct drip_commons_ns0_result *xmlTextReaderReadNs0ResultElement(xmlTextReaderPtr reader) {
  struct drip_commons_ns0_result *_result = NULL;

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "result", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Attempting to read root element {}result.\n");
#endif
    _result = xmlTextReaderReadNs0ResultType(reader);
  }
#if DEBUG_ENUNCIATE
  if (_result == NULL) {
    if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
      printf("attempt to read {}result failed. current element: {}%s\n",  xmlTextReaderConstLocalName(reader));
    }
    else {
      printf("attempt to read {}result failed. current element: {%s}%s\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader));
    }
  }
#endif

  return _result;
}

/**
 * Writes a Result to XML under element name "result".
 * Does NOT write the namespace prefixes.
 *
 * @param writer The XML writer.
 * @param _result The Result to write.
 * @return 1 if successful, 0 otherwise.
 */
static int xmlTextWriterWriteNs0ResultElement(xmlTextWriterPtr writer, struct drip_commons_ns0_result *_result) {
  return xmlTextWriterWriteNs0ResultElementNS(writer, _result, 0);
}

/**
 * Writes a Result to XML under element name "result".
 *
 * @param writer The XML writer.
 * @param _result The Result to write.
 * @param writeNamespaces Whether to write the namespace prefixes.
 * @return 1 if successful, 0 otherwise.
 */
static int xmlTextWriterWriteNs0ResultElementNS(xmlTextWriterPtr writer, struct drip_commons_ns0_result *_result, int writeNamespaces) {
  int totalBytes = 0;
  int status;

  status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "result", NULL);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to write start element {}result. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

#if DEBUG_ENUNCIATE > 1
  printf("writing type {}result for root element {}result...\n");
#endif
  status = xmlTextWriterWriteNs0ResultType(writer, _result);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to write type for start element {}result. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

  status = xmlTextWriterEndElement(writer);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to end element {}result. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

  return totalBytes;
}

/**
 * Frees the children of a Result.
 *
 * @param _result The Result whose children are to be free.
 */
static void freeNs0ResultElement(struct drip_commons_ns0_result *_result) {
  freeNs0ResultType(_result);
}

/**
 * Reads a Result from XML. The reader is assumed to be at the start element.
 *
 * @return the Result, or NULL in case of error.
 */
static struct drip_commons_ns0_result *xmlTextReaderReadNs0ResultType(xmlTextReaderPtr reader) {
  int status, depth;
  void *_child_accessor;
  struct drip_commons_ns0_result *_result = calloc(1, sizeof(struct drip_commons_ns0_result));



  if (xmlTextReaderIsEmptyElement(reader) == 0) {
    depth = xmlTextReaderDepth(reader);//track the depth.
    status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);

    while (xmlTextReaderDepth(reader) > depth) {
      if (status < 1) {
        //panic: XML read error.
#if DEBUG_ENUNCIATE
        printf("Failure to advance to next child element.\n");
#endif
        freeNs0ResultType(_result);
        free(_result);
        return NULL;
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "status", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}status of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}status of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ResultType(_result);
          free(_result);
          return NULL;
        }

        _result->status = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "info", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}info of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}info of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ResultType(_result);
          free(_result);
          return NULL;
        }

        _result->info = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "file", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}file of type {}attribute.\n");
#endif
        _child_accessor = xmlTextReaderReadNs0AttributeType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}file of type {}attribute.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0ResultType(_result);
          free(_result);
          return NULL;
        }

        _result->file = realloc(_result->file, (_result->_sizeof_file + 1) * sizeof(struct drip_commons_ns0_attribute));
        memcpy(&(_result->file[_result->_sizeof_file++]), _child_accessor, sizeof(struct drip_commons_ns0_attribute));
        free(_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else {
#if DEBUG_ENUNCIATE > 1
        if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
          printf("unknown child element {}%s for type {}result.  Skipping...\n",  xmlTextReaderConstLocalName(reader));
        }
        else {
          printf("unknown child element {%s}%s for type {}result. Skipping...\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader));
        }
#endif
        status = xmlTextReaderSkipElement(reader);
      }
    }
  }

  return _result;
}

/**
 * Writes a Result to XML.
 *
 * @param writer The XML writer.
 * @param _result The Result to write.
 * @return The total bytes written, or -1 on error;
 */
static int xmlTextWriterWriteNs0ResultType(xmlTextWriterPtr writer, struct drip_commons_ns0_result *_result) {
  int status, totalBytes = 0, i;
  xmlChar *binaryData;
  if (_result->status != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "status", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}status. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}status...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_result->status));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}status. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}status. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_result->info != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "info", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}info. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}info...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_result->info));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}info. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}info. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  for (i = 0; i < _result->_sizeof_file; i++) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "file", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}file. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {}attribute for element {}file...\n");
#endif
    status = xmlTextWriterWriteNs0AttributeType(writer, &(_result->file[i]));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {}attribute for element {}file. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}file. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }

  return totalBytes;
}

/**
 * Frees the elements of a Result.
 *
 * @param _result The Result to free.
 */
static void freeNs0ResultType(struct drip_commons_ns0_result *_result) {
  int i;
  if (_result->status != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor status of type drip_commons_ns0_result...\n");
#endif
    freeXsStringType(_result->status);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor status of type drip_commons_ns0_result...\n");
#endif
    free(_result->status);
  }
  if (_result->info != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor info of type drip_commons_ns0_result...\n");
#endif
    freeXsStringType(_result->info);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor info of type drip_commons_ns0_result...\n");
#endif
    free(_result->info);
  }
  if (_result->file != NULL) {
    for (i = 0; i < _result->_sizeof_file; i++) {
#if DEBUG_ENUNCIATE > 1
      printf("Freeing accessor file[%i] of type drip_commons_ns0_result...\n", i);
#endif
      freeNs0AttributeType(&(_result->file[i]));
    }
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor file of type drip_commons_ns0_result...\n");
#endif
    free(_result->file);
  }
}
#endif /* DEF_drip_commons_ns0_result_M */
#ifndef DEF_drip_commons_ns0_upload_M
#define DEF_drip_commons_ns0_upload_M

/**
 * Reads a Upload element from XML. The element to be read is "upload", and
 * it is assumed that the reader is pointing to the XML document (not the element).
 *
 * @param reader The XML reader.
 * @return The Upload, or NULL in case of error.
 */
struct drip_commons_ns0_upload *xml_read_drip_commons_ns0_upload(xmlTextReaderPtr reader) {
  int status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
  return xmlTextReaderReadNs0UploadElement(reader);
}

/**
 * Writes a Upload to XML under element name "upload".
 *
 * @param writer The XML writer.
 * @param _upload The Upload to write.
 * @return 1 if successful, 0 otherwise.
 */
int xml_write_drip_commons_ns0_upload(xmlTextWriterPtr writer, struct drip_commons_ns0_upload *_upload) {
  return xmlTextWriterWriteNs0UploadElementNS(writer, _upload, 1);
}

/**
 * Frees a Upload.
 *
 * @param _upload The Upload to free.
 */
void free_drip_commons_ns0_upload(struct drip_commons_ns0_upload *_upload) {
  freeNs0UploadType(_upload);
  free(_upload);
}

/**
 * Reads a Upload element from XML. The element to be read is "upload", and
 * it is assumed that the reader is pointing to that element.
 *
 * @param reader The XML reader.
 * @return The Upload, or NULL in case of error.
 */
struct drip_commons_ns0_upload *xmlTextReaderReadNs0UploadElement(xmlTextReaderPtr reader) {
  struct drip_commons_ns0_upload *_upload = NULL;

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "upload", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Attempting to read root element {}upload.\n");
#endif
    _upload = xmlTextReaderReadNs0UploadType(reader);
  }
#if DEBUG_ENUNCIATE
  if (_upload == NULL) {
    if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
      printf("attempt to read {}upload failed. current element: {}%s\n",  xmlTextReaderConstLocalName(reader));
    }
    else {
      printf("attempt to read {}upload failed. current element: {%s}%s\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader));
    }
  }
#endif

  return _upload;
}

/**
 * Writes a Upload to XML under element name "upload".
 * Does NOT write the namespace prefixes.
 *
 * @param writer The XML writer.
 * @param _upload The Upload to write.
 * @return 1 if successful, 0 otherwise.
 */
static int xmlTextWriterWriteNs0UploadElement(xmlTextWriterPtr writer, struct drip_commons_ns0_upload *_upload) {
  return xmlTextWriterWriteNs0UploadElementNS(writer, _upload, 0);
}

/**
 * Writes a Upload to XML under element name "upload".
 *
 * @param writer The XML writer.
 * @param _upload The Upload to write.
 * @param writeNamespaces Whether to write the namespace prefixes.
 * @return 1 if successful, 0 otherwise.
 */
static int xmlTextWriterWriteNs0UploadElementNS(xmlTextWriterPtr writer, struct drip_commons_ns0_upload *_upload, int writeNamespaces) {
  int totalBytes = 0;
  int status;

  status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "upload", NULL);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to write start element {}upload. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

#if DEBUG_ENUNCIATE > 1
  printf("writing type {}upload for root element {}upload...\n");
#endif
  status = xmlTextWriterWriteNs0UploadType(writer, _upload);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to write type for start element {}upload. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

  status = xmlTextWriterEndElement(writer);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to end element {}upload. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

  return totalBytes;
}

/**
 * Frees the children of a Upload.
 *
 * @param _upload The Upload whose children are to be free.
 */
static void freeNs0UploadElement(struct drip_commons_ns0_upload *_upload) {
  freeNs0UploadType(_upload);
}

/**
 * Reads a Upload from XML. The reader is assumed to be at the start element.
 *
 * @return the Upload, or NULL in case of error.
 */
static struct drip_commons_ns0_upload *xmlTextReaderReadNs0UploadType(xmlTextReaderPtr reader) {
  int status, depth;
  void *_child_accessor;
  struct drip_commons_ns0_upload *_upload = calloc(1, sizeof(struct drip_commons_ns0_upload));



  if (xmlTextReaderIsEmptyElement(reader) == 0) {
    depth = xmlTextReaderDepth(reader);//track the depth.
    status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);

    while (xmlTextReaderDepth(reader) > depth) {
      if (status < 1) {
        //panic: XML read error.
#if DEBUG_ENUNCIATE
        printf("Failure to advance to next child element.\n");
#endif
        freeNs0UploadType(_upload);
        free(_upload);
        return NULL;
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "user", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0UploadType(_upload);
          free(_upload);
          return NULL;
        }

        _upload->user = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "pwd", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0UploadType(_upload);
          free(_upload);
          return NULL;
        }

        _upload->pwd = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "file", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}file of type {}attribute.\n");
#endif
        _child_accessor = xmlTextReaderReadNs0AttributeType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}file of type {}attribute.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeNs0UploadType(_upload);
          free(_upload);
          return NULL;
        }

        _upload->file = realloc(_upload->file, (_upload->_sizeof_file + 1) * sizeof(struct drip_commons_ns0_attribute));
        memcpy(&(_upload->file[_upload->_sizeof_file++]), _child_accessor, sizeof(struct drip_commons_ns0_attribute));
        free(_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else {
#if DEBUG_ENUNCIATE > 1
        if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
          printf("unknown child element {}%s for type {}upload.  Skipping...\n",  xmlTextReaderConstLocalName(reader));
        }
        else {
          printf("unknown child element {%s}%s for type {}upload. Skipping...\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader));
        }
#endif
        status = xmlTextReaderSkipElement(reader);
      }
    }
  }

  return _upload;
}

/**
 * Writes a Upload to XML.
 *
 * @param writer The XML writer.
 * @param _upload The Upload to write.
 * @return The total bytes written, or -1 on error;
 */
static int xmlTextWriterWriteNs0UploadType(xmlTextWriterPtr writer, struct drip_commons_ns0_upload *_upload) {
  int status, totalBytes = 0, i;
  xmlChar *binaryData;
  if (_upload->user != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "user", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}user...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_upload->user));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}user. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_upload->pwd != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "pwd", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}pwd...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_upload->pwd));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}pwd. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  for (i = 0; i < _upload->_sizeof_file; i++) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "file", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}file. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {}attribute for element {}file...\n");
#endif
    status = xmlTextWriterWriteNs0AttributeType(writer, &(_upload->file[i]));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {}attribute for element {}file. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}file. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }

  return totalBytes;
}

/**
 * Frees the elements of a Upload.
 *
 * @param _upload The Upload to free.
 */
static void freeNs0UploadType(struct drip_commons_ns0_upload *_upload) {
  int i;
  if (_upload->user != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor user of type drip_commons_ns0_upload...\n");
#endif
    freeXsStringType(_upload->user);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor user of type drip_commons_ns0_upload...\n");
#endif
    free(_upload->user);
  }
  if (_upload->pwd != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor pwd of type drip_commons_ns0_upload...\n");
#endif
    freeXsStringType(_upload->pwd);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor pwd of type drip_commons_ns0_upload...\n");
#endif
    free(_upload->pwd);
  }
  if (_upload->file != NULL) {
    for (i = 0; i < _upload->_sizeof_file; i++) {
#if DEBUG_ENUNCIATE > 1
      printf("Freeing accessor file[%i] of type drip_commons_ns0_upload...\n", i);
#endif
      freeNs0AttributeType(&(_upload->file[i]));
    }
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor file of type drip_commons_ns0_upload...\n");
#endif
    free(_upload->file);
  }
}
#endif /* DEF_drip_commons_ns0_upload_M */
