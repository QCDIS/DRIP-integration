#import "drip-commons.h"
#ifndef DEF_DRIP_COMMONSNS0Execute_M
#define DEF_DRIP_COMMONSNS0Execute_M

/**
 * 
 *  @author S. Koulouzis
 */
@implementation DRIP_COMMONSNS0Execute

/**
 * Not used. It's there for backwards compatibility.
 */
- (NSString *) user
{
  return _user;
}

/**
 * Not used. It's there for backwards compatibility.
 */
- (void) setUser: (NSString *) newUser
{
  [newUser retain];
  [_user release];
  _user = newUser;
}

/**
 * Not used. It's there for backwards compatibility.
 */
- (NSString *) pwd
{
  return _pwd;
}

/**
 * Not used. It's there for backwards compatibility.
 */
- (void) setPwd: (NSString *) newPwd
{
  [newPwd retain];
  [_pwd release];
  _pwd = newPwd;
}

/**
 * A referance id used from the servcie to do the provisioning
 */
- (NSString *) action
{
  return _action;
}

/**
 * A referance id used from the servcie to do the provisioning
 */
- (void) setAction: (NSString *) newAction
{
  [newAction retain];
  [_action release];
  _action = newAction;
}

- (void) dealloc
{
  [self setUser: nil];
  [self setPwd: nil];
  [self setAction: nil];
  [super dealloc];
}

//documentation inherited.
+ (id<EnunciateXML>) readFromXML: (NSData *) xml
{
  DRIP_COMMONSNS0Execute *_dRIP_COMMONSNS0Execute;
  xmlTextReaderPtr reader = xmlReaderForMemory([xml bytes], [xml length], NULL, NULL, 0);
  if (reader == NULL) {
    [NSException raise: @"XMLReadError"
                 format: @"Error instantiating an XML reader."];
    return nil;
  }

  _dRIP_COMMONSNS0Execute = (DRIP_COMMONSNS0Execute *) [DRIP_COMMONSNS0Execute readXMLElement: reader];
  xmlFreeTextReader(reader); //free the reader
  return _dRIP_COMMONSNS0Execute;
}

//documentation inherited.
- (NSData *) writeToXML
{
  xmlBufferPtr buf;
  xmlTextWriterPtr writer;
  int rc;
  NSData *data;

  buf = xmlBufferCreate();
  if (buf == NULL) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error creating an XML buffer."];
    return nil;
  }

  writer = xmlNewTextWriterMemory(buf, 0);
  if (writer == NULL) {
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error creating an XML writer."];
    return nil;
  }

  rc = xmlTextWriterStartDocument(writer, NULL, "utf-8", NULL);
  if (rc < 0) {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing XML start document."];
    return nil;
  }

  NS_DURING
  {
    [self writeXMLElement: writer];
  }
  NS_HANDLER
  {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [localException raise];
  }
  NS_ENDHANDLER

  rc = xmlTextWriterEndDocument(writer);
  if (rc < 0) {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing XML end document."];
    return nil;
  }

  xmlFreeTextWriter(writer);
  data = [NSData dataWithBytes: buf->content length: buf->use];
  xmlBufferFree(buf);
  return data;
}
@end /* implementation DRIP_COMMONSNS0Execute */

/**
 * Internal, private interface for JAXB reading and writing.
 */
@interface DRIP_COMMONSNS0Execute (JAXB) <JAXBReading, JAXBWriting, JAXBType, JAXBElement>

@end /*interface DRIP_COMMONSNS0Execute (JAXB)*/

/**
 * Internal, private implementation for JAXB reading and writing.
 */
@implementation DRIP_COMMONSNS0Execute (JAXB)

/**
 * Read an instance of DRIP_COMMONSNS0Execute from an XML reader.
 *
 * @param reader The reader.
 * @return An instance of DRIP_COMMONSNS0Execute defined by the XML reader.
 */
+ (id<JAXBType>) readXMLType: (xmlTextReaderPtr) reader
{
  DRIP_COMMONSNS0Execute *_dRIP_COMMONSNS0Execute = [[DRIP_COMMONSNS0Execute alloc] init];
  NS_DURING
  {
    [_dRIP_COMMONSNS0Execute initWithReader: reader];
  }
  NS_HANDLER
  {
    _dRIP_COMMONSNS0Execute = nil;
    [localException raise];
  }
  NS_ENDHANDLER

  [_dRIP_COMMONSNS0Execute autorelease];
  return _dRIP_COMMONSNS0Execute;
}

/**
 * Initialize this instance of DRIP_COMMONSNS0Execute according to
 * the XML being read from the reader.
 *
 * @param reader The reader.
 */
- (id) initWithReader: (xmlTextReaderPtr) reader
{
  return [super initWithReader: reader];
}

/**
 * Write the XML for this instance of DRIP_COMMONSNS0Execute to the writer.
 * Note that since we're only writing the XML type,
 * No start/end element will be written.
 *
 * @param reader The reader.
 */
- (void) writeXMLType: (xmlTextWriterPtr) writer
{
  [super writeXMLType:writer];
}

/**
 * Reads a DRIP_COMMONSNS0Execute from an XML reader. The element to be read is
 * "execute".
 *
 * @param reader The XML reader.
 * @return The DRIP_COMMONSNS0Execute.
 */
+ (id<JAXBElement>) readXMLElement: (xmlTextReaderPtr) reader {
  int status;
  DRIP_COMMONSNS0Execute *_execute = nil;

  if (xmlTextReaderNodeType(reader) != XML_READER_TYPE_ELEMENT) {
    status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
    if (status < 1) {
      [NSException raise: @"XMLReadError"
                   format: @"Error advancing the reader to start element execute."];
    }
  }

  if (xmlStrcmp(BAD_CAST "execute", xmlTextReaderConstLocalName(reader)) == 0
      && xmlTextReaderConstNamespaceUri(reader) == NULL) {
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read root element {}execute.");
#endif
    _execute = (DRIP_COMMONSNS0Execute *)[DRIP_COMMONSNS0Execute readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Successfully read root element {}execute.");
#endif
  }
  else {
    if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
      [NSException raise: @"XMLReadError"
                   format: @"Unable to read DRIP_COMMONSNS0Execute. Expected element execute. Current element: {}%s", xmlTextReaderConstLocalName(reader)];
    }
    else {
      [NSException raise: @"XMLReadError"
                   format: @"Unable to read DRIP_COMMONSNS0Execute. Expected element execute. Current element: {%s}%s\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader)];
    }
  }

  return _execute;
}

/**
 * Writes this DRIP_COMMONSNS0Execute to XML under element name "execute".
 * The namespace declarations for the element will be written.
 *
 * @param writer The XML writer.
 * @param _execute The Execute to write.
 * @return 1 if successful, 0 otherwise.
 */
- (void) writeXMLElement: (xmlTextWriterPtr) writer
{
  [self writeXMLElement: writer writeNamespaces: YES];
}

/**
 * Writes this DRIP_COMMONSNS0Execute to an XML writer.
 *
 * @param writer The writer.
 * @param writeNs Whether to write the namespaces for this element to the xml writer.
 */
- (void) writeXMLElement: (xmlTextWriterPtr) writer writeNamespaces: (BOOL) writeNs
{
  int rc = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "execute", NULL);
  if (rc < 0) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing start element {}execute. XML writer status: %i\n", rc];
  }

#if DEBUG_ENUNCIATE > 1
  NSLog(@"writing type {}execute for root element {}execute...");
#endif
  [self writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
  NSLog(@"successfully wrote type {}execute for root element {}execute...");
#endif
  rc = xmlTextWriterEndElement(writer);
  if (rc < 0) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing end element {}execute. XML writer status: %i\n", rc];
  }
}

//documentation inherited.
- (BOOL) readJAXBAttribute: (xmlTextReaderPtr) reader
{
  void *_child_accessor;

  if ([super readJAXBAttribute: reader]) {
    return YES;
  }

  return NO;
}

//documentation inherited.
- (BOOL) readJAXBValue: (xmlTextReaderPtr) reader
{
  return [super readJAXBValue: reader];
}

//documentation inherited.
- (BOOL) readJAXBChildElement: (xmlTextReaderPtr) reader
{
  id __child;
  void *_child_accessor;
  int status, depth;

  if ([super readJAXBChildElement: reader]) {
    return YES;
  }
  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "user", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setUser: __child];
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "pwd", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setPwd: __child];
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "action", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}action of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}action of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setAction: __child];
    return YES;
  } //end "if choice"


  return NO;
}

//documentation inherited.
- (int) readUnknownJAXBChildElement: (xmlTextReaderPtr) reader
{
  return [super readUnknownJAXBChildElement: reader];
}

//documentation inherited.
- (void) readUnknownJAXBAttribute: (xmlTextReaderPtr) reader
{
  [super readUnknownJAXBAttribute: reader];
}

//documentation inherited.
- (void) writeJAXBAttributes: (xmlTextWriterPtr) writer
{
  int status;

  [super writeJAXBAttributes: writer];

}

//documentation inherited.
- (void) writeJAXBValue: (xmlTextWriterPtr) writer
{
  [super writeJAXBValue: writer];
}

/**
 * Method for writing the child elements.
 *
 * @param writer The writer.
 */
- (void) writeJAXBChildElements: (xmlTextWriterPtr) writer
{
  int status;
  id __item;
  id __item_copy;
  NSEnumerator *__enumerator;

  [super writeJAXBChildElements: writer];

  if ([self user]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "user", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}user."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}user...");
#endif
    [[self user] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}user...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}user."];
    }
  }
  if ([self pwd]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "pwd", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}pwd."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}pwd...");
#endif
    [[self pwd] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}pwd...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}pwd."];
    }
  }
  if ([self action]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "action", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}action."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}action...");
#endif
    [[self action] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}action...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}action."];
    }
  }
}
@end /* implementation DRIP_COMMONSNS0Execute (JAXB) */

#endif /* DEF_DRIP_COMMONSNS0Execute_M */
#ifndef DEF_DRIP_COMMONSNS0Configure_M
#define DEF_DRIP_COMMONSNS0Configure_M

/**
 * 
 *  @author S. Koulouzis
 */
@implementation DRIP_COMMONSNS0Configure

/**
 * Not used. It's there for backwards compatibility.
 */
- (NSString *) user
{
  return _user;
}

/**
 * Not used. It's there for backwards compatibility.
 */
- (void) setUser: (NSString *) newUser
{
  [newUser retain];
  [_user release];
  _user = newUser;
}

/**
 * Not used. It's there for backwards compatibility.
 */
- (NSString *) pwd
{
  return _pwd;
}

/**
 * Not used. It's there for backwards compatibility.
 */
- (void) setPwd: (NSString *) newPwd
{
  [newPwd retain];
  [_pwd release];
  _pwd = newPwd;
}

/**
 * The key id for the cloud provider.
 */
- (NSString *) keyid
{
  return _keyid;
}

/**
 * The key id for the cloud provider.
 */
- (void) setKeyid: (NSString *) newKeyid
{
  [newKeyid retain];
  [_keyid release];
  _keyid = newKeyid;
}

/**
 * The key for the cloud provider.
 */
- (NSString *) key
{
  return _key;
}

/**
 * The key for the cloud provider.
 */
- (void) setKey: (NSString *) newKey
{
  [newKey retain];
  [_key release];
  _key = newKey;
}

/**
 * (no documentation provided)
 */
- (NSArray *) loginKey
{
  return _loginKey;
}

/**
 * (no documentation provided)
 */
- (void) setLoginKey: (NSArray *) newLoginKey
{
  [newLoginKey retain];
  [_loginKey release];
  _loginKey = newLoginKey;
}

/**
 * The binary keystore (user.jks) for the cloud provider encoded in base64
 */
- (NSString *) geniKey
{
  return _geniKey;
}

/**
 * The binary keystore (user.jks) for the cloud provider encoded in base64
 */
- (void) setGeniKey: (NSString *) newGeniKey
{
  [newGeniKey retain];
  [_geniKey release];
  _geniKey = newGeniKey;
}

/**
 * Key alias in key store
 */
- (NSString *) geniKeyAlias
{
  return _geniKeyAlias;
}

/**
 * Key alias in key store
 */
- (void) setGeniKeyAlias: (NSString *) newGeniKeyAlias
{
  [newGeniKeyAlias retain];
  [_geniKeyAlias release];
  _geniKeyAlias = newGeniKeyAlias;
}

/**
 * (no documentation provided)
 */
- (NSArray *) loginPubKey
{
  return _loginPubKey;
}

/**
 * (no documentation provided)
 */
- (void) setLoginPubKey: (NSArray *) newLoginPubKey
{
  [newLoginPubKey retain];
  [_loginPubKey release];
  _loginPubKey = newLoginPubKey;
}

/**
 * (no documentation provided)
 */
- (NSString *) geniKeyPass
{
  return _geniKeyPass;
}

/**
 * (no documentation provided)
 */
- (void) setGeniKeyPass: (NSString *) newGeniKeyPass
{
  [newGeniKeyPass retain];
  [_geniKeyPass release];
  _geniKeyPass = newGeniKeyPass;
}

/**
 * (no documentation provided)
 */
- (NSArray *) loginPriKey
{
  return _loginPriKey;
}

/**
 * (no documentation provided)
 */
- (void) setLoginPriKey: (NSArray *) newLoginPriKey
{
  [newLoginPriKey retain];
  [_loginPriKey release];
  _loginPriKey = newLoginPriKey;
}

- (void) dealloc
{
  [self setUser: nil];
  [self setPwd: nil];
  [self setKeyid: nil];
  [self setKey: nil];
  [self setLoginKey: nil];
  [self setGeniKey: nil];
  [self setGeniKeyAlias: nil];
  [self setLoginPubKey: nil];
  [self setGeniKeyPass: nil];
  [self setLoginPriKey: nil];
  [super dealloc];
}

//documentation inherited.
+ (id<EnunciateXML>) readFromXML: (NSData *) xml
{
  DRIP_COMMONSNS0Configure *_dRIP_COMMONSNS0Configure;
  xmlTextReaderPtr reader = xmlReaderForMemory([xml bytes], [xml length], NULL, NULL, 0);
  if (reader == NULL) {
    [NSException raise: @"XMLReadError"
                 format: @"Error instantiating an XML reader."];
    return nil;
  }

  _dRIP_COMMONSNS0Configure = (DRIP_COMMONSNS0Configure *) [DRIP_COMMONSNS0Configure readXMLElement: reader];
  xmlFreeTextReader(reader); //free the reader
  return _dRIP_COMMONSNS0Configure;
}

//documentation inherited.
- (NSData *) writeToXML
{
  xmlBufferPtr buf;
  xmlTextWriterPtr writer;
  int rc;
  NSData *data;

  buf = xmlBufferCreate();
  if (buf == NULL) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error creating an XML buffer."];
    return nil;
  }

  writer = xmlNewTextWriterMemory(buf, 0);
  if (writer == NULL) {
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error creating an XML writer."];
    return nil;
  }

  rc = xmlTextWriterStartDocument(writer, NULL, "utf-8", NULL);
  if (rc < 0) {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing XML start document."];
    return nil;
  }

  NS_DURING
  {
    [self writeXMLElement: writer];
  }
  NS_HANDLER
  {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [localException raise];
  }
  NS_ENDHANDLER

  rc = xmlTextWriterEndDocument(writer);
  if (rc < 0) {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing XML end document."];
    return nil;
  }

  xmlFreeTextWriter(writer);
  data = [NSData dataWithBytes: buf->content length: buf->use];
  xmlBufferFree(buf);
  return data;
}
@end /* implementation DRIP_COMMONSNS0Configure */

/**
 * Internal, private interface for JAXB reading and writing.
 */
@interface DRIP_COMMONSNS0Configure (JAXB) <JAXBReading, JAXBWriting, JAXBType, JAXBElement>

@end /*interface DRIP_COMMONSNS0Configure (JAXB)*/

/**
 * Internal, private implementation for JAXB reading and writing.
 */
@implementation DRIP_COMMONSNS0Configure (JAXB)

/**
 * Read an instance of DRIP_COMMONSNS0Configure from an XML reader.
 *
 * @param reader The reader.
 * @return An instance of DRIP_COMMONSNS0Configure defined by the XML reader.
 */
+ (id<JAXBType>) readXMLType: (xmlTextReaderPtr) reader
{
  DRIP_COMMONSNS0Configure *_dRIP_COMMONSNS0Configure = [[DRIP_COMMONSNS0Configure alloc] init];
  NS_DURING
  {
    [_dRIP_COMMONSNS0Configure initWithReader: reader];
  }
  NS_HANDLER
  {
    _dRIP_COMMONSNS0Configure = nil;
    [localException raise];
  }
  NS_ENDHANDLER

  [_dRIP_COMMONSNS0Configure autorelease];
  return _dRIP_COMMONSNS0Configure;
}

/**
 * Initialize this instance of DRIP_COMMONSNS0Configure according to
 * the XML being read from the reader.
 *
 * @param reader The reader.
 */
- (id) initWithReader: (xmlTextReaderPtr) reader
{
  return [super initWithReader: reader];
}

/**
 * Write the XML for this instance of DRIP_COMMONSNS0Configure to the writer.
 * Note that since we're only writing the XML type,
 * No start/end element will be written.
 *
 * @param reader The reader.
 */
- (void) writeXMLType: (xmlTextWriterPtr) writer
{
  [super writeXMLType:writer];
}

/**
 * Reads a DRIP_COMMONSNS0Configure from an XML reader. The element to be read is
 * "configure".
 *
 * @param reader The XML reader.
 * @return The DRIP_COMMONSNS0Configure.
 */
+ (id<JAXBElement>) readXMLElement: (xmlTextReaderPtr) reader {
  int status;
  DRIP_COMMONSNS0Configure *_configure = nil;

  if (xmlTextReaderNodeType(reader) != XML_READER_TYPE_ELEMENT) {
    status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
    if (status < 1) {
      [NSException raise: @"XMLReadError"
                   format: @"Error advancing the reader to start element configure."];
    }
  }

  if (xmlStrcmp(BAD_CAST "configure", xmlTextReaderConstLocalName(reader)) == 0
      && xmlTextReaderConstNamespaceUri(reader) == NULL) {
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read root element {}configure.");
#endif
    _configure = (DRIP_COMMONSNS0Configure *)[DRIP_COMMONSNS0Configure readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Successfully read root element {}configure.");
#endif
  }
  else {
    if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
      [NSException raise: @"XMLReadError"
                   format: @"Unable to read DRIP_COMMONSNS0Configure. Expected element configure. Current element: {}%s", xmlTextReaderConstLocalName(reader)];
    }
    else {
      [NSException raise: @"XMLReadError"
                   format: @"Unable to read DRIP_COMMONSNS0Configure. Expected element configure. Current element: {%s}%s\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader)];
    }
  }

  return _configure;
}

/**
 * Writes this DRIP_COMMONSNS0Configure to XML under element name "configure".
 * The namespace declarations for the element will be written.
 *
 * @param writer The XML writer.
 * @param _configure The Configure to write.
 * @return 1 if successful, 0 otherwise.
 */
- (void) writeXMLElement: (xmlTextWriterPtr) writer
{
  [self writeXMLElement: writer writeNamespaces: YES];
}

/**
 * Writes this DRIP_COMMONSNS0Configure to an XML writer.
 *
 * @param writer The writer.
 * @param writeNs Whether to write the namespaces for this element to the xml writer.
 */
- (void) writeXMLElement: (xmlTextWriterPtr) writer writeNamespaces: (BOOL) writeNs
{
  int rc = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "configure", NULL);
  if (rc < 0) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing start element {}configure. XML writer status: %i\n", rc];
  }

#if DEBUG_ENUNCIATE > 1
  NSLog(@"writing type {}configure for root element {}configure...");
#endif
  [self writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
  NSLog(@"successfully wrote type {}configure for root element {}configure...");
#endif
  rc = xmlTextWriterEndElement(writer);
  if (rc < 0) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing end element {}configure. XML writer status: %i\n", rc];
  }
}

//documentation inherited.
- (BOOL) readJAXBAttribute: (xmlTextReaderPtr) reader
{
  void *_child_accessor;

  if ([super readJAXBAttribute: reader]) {
    return YES;
  }

  return NO;
}

//documentation inherited.
- (BOOL) readJAXBValue: (xmlTextReaderPtr) reader
{
  return [super readJAXBValue: reader];
}

//documentation inherited.
- (BOOL) readJAXBChildElement: (xmlTextReaderPtr) reader
{
  id __child;
  void *_child_accessor;
  int status, depth;

  if ([super readJAXBChildElement: reader]) {
    return YES;
  }
  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "user", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setUser: __child];
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "pwd", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setPwd: __child];
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "keyid", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}keyid of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}keyid of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setKeyid: __child];
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "key", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}key of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}key of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setKey: __child];
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "loginKey", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}loginKey of type {}loginKey0.");
#endif

     __child = [DRIP_COMMONSNS0LoginKey0 readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}loginKey of type {}loginKey0.");
#endif

    if ([self loginKey]) {
      [self setLoginKey: [[self loginKey] arrayByAddingObject: __child]];
    }
    else {
      [self setLoginKey: [NSArray arrayWithObject: __child]];
    }
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "geniKey", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}geniKey of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}geniKey of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setGeniKey: __child];
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "geniKeyAlias", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}geniKeyAlias of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}geniKeyAlias of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setGeniKeyAlias: __child];
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "loginPubKey", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}loginPubKey of type {}loginKey0.");
#endif

     __child = [DRIP_COMMONSNS0LoginKey0 readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}loginPubKey of type {}loginKey0.");
#endif

    if ([self loginPubKey]) {
      [self setLoginPubKey: [[self loginPubKey] arrayByAddingObject: __child]];
    }
    else {
      [self setLoginPubKey: [NSArray arrayWithObject: __child]];
    }
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "geniKeyPass", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}geniKeyPass of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}geniKeyPass of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setGeniKeyPass: __child];
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "loginPriKey", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}loginPriKey of type {}loginKey0.");
#endif

     __child = [DRIP_COMMONSNS0LoginKey0 readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}loginPriKey of type {}loginKey0.");
#endif

    if ([self loginPriKey]) {
      [self setLoginPriKey: [[self loginPriKey] arrayByAddingObject: __child]];
    }
    else {
      [self setLoginPriKey: [NSArray arrayWithObject: __child]];
    }
    return YES;
  } //end "if choice"


  return NO;
}

//documentation inherited.
- (int) readUnknownJAXBChildElement: (xmlTextReaderPtr) reader
{
  return [super readUnknownJAXBChildElement: reader];
}

//documentation inherited.
- (void) readUnknownJAXBAttribute: (xmlTextReaderPtr) reader
{
  [super readUnknownJAXBAttribute: reader];
}

//documentation inherited.
- (void) writeJAXBAttributes: (xmlTextWriterPtr) writer
{
  int status;

  [super writeJAXBAttributes: writer];

}

//documentation inherited.
- (void) writeJAXBValue: (xmlTextWriterPtr) writer
{
  [super writeJAXBValue: writer];
}

/**
 * Method for writing the child elements.
 *
 * @param writer The writer.
 */
- (void) writeJAXBChildElements: (xmlTextWriterPtr) writer
{
  int status;
  id __item;
  id __item_copy;
  NSEnumerator *__enumerator;

  [super writeJAXBChildElements: writer];

  if ([self user]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "user", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}user."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}user...");
#endif
    [[self user] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}user...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}user."];
    }
  }
  if ([self pwd]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "pwd", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}pwd."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}pwd...");
#endif
    [[self pwd] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}pwd...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}pwd."];
    }
  }
  if ([self keyid]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "keyid", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}keyid."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}keyid...");
#endif
    [[self keyid] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}keyid...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}keyid."];
    }
  }
  if ([self key]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "key", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}key."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}key...");
#endif
    [[self key] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}key...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}key."];
    }
  }
  if ([self loginKey]) {
    __enumerator = [[self loginKey] objectEnumerator];

    while ( (__item = [__enumerator nextObject]) ) {
      status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "loginKey", NULL);
      if (status < 0) {
        [NSException raise: @"XMLWriteError"
                     format: @"Error writing start child element {}loginKey."];
      }

#if DEBUG_ENUNCIATE > 1
      NSLog(@"writing element {}loginKey...");
#endif
      [__item writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
      NSLog(@"successfully wrote element {}loginKey...");
#endif

      status = xmlTextWriterEndElement(writer);
      if (status < 0) {
        [NSException raise: @"XMLWriteError"
                     format: @"Error writing end child element {}loginKey."];
      }
    } //end item iterator.
  }
  if ([self geniKey]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "geniKey", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}geniKey."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}geniKey...");
#endif
    [[self geniKey] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}geniKey...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}geniKey."];
    }
  }
  if ([self geniKeyAlias]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "geniKeyAlias", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}geniKeyAlias."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}geniKeyAlias...");
#endif
    [[self geniKeyAlias] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}geniKeyAlias...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}geniKeyAlias."];
    }
  }
  if ([self loginPubKey]) {
    __enumerator = [[self loginPubKey] objectEnumerator];

    while ( (__item = [__enumerator nextObject]) ) {
      status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "loginPubKey", NULL);
      if (status < 0) {
        [NSException raise: @"XMLWriteError"
                     format: @"Error writing start child element {}loginPubKey."];
      }

#if DEBUG_ENUNCIATE > 1
      NSLog(@"writing element {}loginPubKey...");
#endif
      [__item writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
      NSLog(@"successfully wrote element {}loginPubKey...");
#endif

      status = xmlTextWriterEndElement(writer);
      if (status < 0) {
        [NSException raise: @"XMLWriteError"
                     format: @"Error writing end child element {}loginPubKey."];
      }
    } //end item iterator.
  }
  if ([self geniKeyPass]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "geniKeyPass", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}geniKeyPass."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}geniKeyPass...");
#endif
    [[self geniKeyPass] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}geniKeyPass...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}geniKeyPass."];
    }
  }
  if ([self loginPriKey]) {
    __enumerator = [[self loginPriKey] objectEnumerator];

    while ( (__item = [__enumerator nextObject]) ) {
      status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "loginPriKey", NULL);
      if (status < 0) {
        [NSException raise: @"XMLWriteError"
                     format: @"Error writing start child element {}loginPriKey."];
      }

#if DEBUG_ENUNCIATE > 1
      NSLog(@"writing element {}loginPriKey...");
#endif
      [__item writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
      NSLog(@"successfully wrote element {}loginPriKey...");
#endif

      status = xmlTextWriterEndElement(writer);
      if (status < 0) {
        [NSException raise: @"XMLWriteError"
                     format: @"Error writing end child element {}loginPriKey."];
      }
    } //end item iterator.
  }
}
@end /* implementation DRIP_COMMONSNS0Configure (JAXB) */

#endif /* DEF_DRIP_COMMONSNS0Configure_M */
#ifndef DEF_DRIP_COMMONSNS0LoginKey0_M
#define DEF_DRIP_COMMONSNS0LoginKey0_M

/**
 * 
 *  @author S. Koulouzis
 */
@implementation DRIP_COMMONSNS0LoginKey0

/**
 * (no documentation provided)
 */
- (NSString *) domain_name
{
  return _domain_name;
}

/**
 * (no documentation provided)
 */
- (void) setDomain_name: (NSString *) newDomain_name
{
  [newDomain_name retain];
  [_domain_name release];
  _domain_name = newDomain_name;
}

/**
 * (no documentation provided)
 */
- (NSString *) content
{
  return _content;
}

/**
 * (no documentation provided)
 */
- (void) setContent: (NSString *) newContent
{
  [newContent retain];
  [_content release];
  _content = newContent;
}

- (void) dealloc
{
  [self setDomain_name: nil];
  [self setContent: nil];
  [super dealloc];
}
@end /* implementation DRIP_COMMONSNS0LoginKey0 */

/**
 * Internal, private interface for JAXB reading and writing.
 */
@interface DRIP_COMMONSNS0LoginKey0 (JAXB) <JAXBReading, JAXBWriting, JAXBType>

@end /*interface DRIP_COMMONSNS0LoginKey0 (JAXB)*/

/**
 * Internal, private implementation for JAXB reading and writing.
 */
@implementation DRIP_COMMONSNS0LoginKey0 (JAXB)

/**
 * Read an instance of DRIP_COMMONSNS0LoginKey0 from an XML reader.
 *
 * @param reader The reader.
 * @return An instance of DRIP_COMMONSNS0LoginKey0 defined by the XML reader.
 */
+ (id<JAXBType>) readXMLType: (xmlTextReaderPtr) reader
{
  DRIP_COMMONSNS0LoginKey0 *_dRIP_COMMONSNS0LoginKey0 = [[DRIP_COMMONSNS0LoginKey0 alloc] init];
  NS_DURING
  {
    [_dRIP_COMMONSNS0LoginKey0 initWithReader: reader];
  }
  NS_HANDLER
  {
    _dRIP_COMMONSNS0LoginKey0 = nil;
    [localException raise];
  }
  NS_ENDHANDLER

  [_dRIP_COMMONSNS0LoginKey0 autorelease];
  return _dRIP_COMMONSNS0LoginKey0;
}

/**
 * Initialize this instance of DRIP_COMMONSNS0LoginKey0 according to
 * the XML being read from the reader.
 *
 * @param reader The reader.
 */
- (id) initWithReader: (xmlTextReaderPtr) reader
{
  return [super initWithReader: reader];
}

/**
 * Write the XML for this instance of DRIP_COMMONSNS0LoginKey0 to the writer.
 * Note that since we're only writing the XML type,
 * No start/end element will be written.
 *
 * @param reader The reader.
 */
- (void) writeXMLType: (xmlTextWriterPtr) writer
{
  [super writeXMLType:writer];
}

//documentation inherited.
- (BOOL) readJAXBAttribute: (xmlTextReaderPtr) reader
{
  void *_child_accessor;

  if ([super readJAXBAttribute: reader]) {
    return YES;
  }

  if ((xmlStrcmp(BAD_CAST "domain_name", xmlTextReaderConstLocalName(reader)) == 0) && (xmlTextReaderConstNamespaceUri(reader) == NULL)) {
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read attribute {}domain_name...");
#endif
    [self setDomain_name: (NSString*) [NSString readXMLType: reader]];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read attribute {}domain_name...");
#endif
    return YES;
  }

  return NO;
}

//documentation inherited.
- (BOOL) readJAXBValue: (xmlTextReaderPtr) reader
{

#if DEBUG_ENUNCIATE > 1
  NSLog(@"Attempting to read element value...");
#endif
  if (xmlTextReaderIsEmptyElement(reader) == 0) {
    [self setContent: (NSString *) [NSString readXMLType: reader]];
  }
  else {
    [self setContent: @""];
  }
#if DEBUG_ENUNCIATE > 1
  NSLog(@"successfully read element value...");
#endif

  return YES;
}
//documentation inherited.
- (BOOL) readJAXBChildElement: (xmlTextReaderPtr) reader
{
  return [super readJAXBChildElement: reader];
}

//documentation inherited.
- (int) readUnknownJAXBChildElement: (xmlTextReaderPtr) reader
{
  return [super readUnknownJAXBChildElement: reader];
}

//documentation inherited.
- (void) readUnknownJAXBAttribute: (xmlTextReaderPtr) reader
{
  [super readUnknownJAXBAttribute: reader];
}

//documentation inherited.
- (void) writeJAXBAttributes: (xmlTextWriterPtr) writer
{
  int status;

  [super writeJAXBAttributes: writer];

  if ([self domain_name]) {

    status = xmlTextWriterStartAttributeNS(writer, NULL, BAD_CAST "domain_name", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start attribute {}domain_name."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing attribute {}domain_name...");
#endif
    [[self domain_name] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote attribute {}domain_name...");
#endif

    status = xmlTextWriterEndAttribute(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end attribute {}domain_name."];
    }
  }
}

//documentation inherited.
- (void) writeJAXBValue: (xmlTextWriterPtr) writer
{
#if DEBUG_ENUNCIATE > 1
  NSLog(@"writing element value...");
#endif
  [[self content] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
  NSLog(@"successfully wrote element value...");
#endif
}

/**
 * Method for writing the child elements.
 *
 * @param writer The writer.
 */
- (void) writeJAXBChildElements: (xmlTextWriterPtr) writer
{
  [super writeJAXBChildElements: writer];
}
@end /* implementation DRIP_COMMONSNS0LoginKey0 (JAXB) */

#endif /* DEF_DRIP_COMMONSNS0LoginKey0_M */
#ifndef DEF_DRIP_COMMONSNS0Register_M
#define DEF_DRIP_COMMONSNS0Register_M

/**
 * 
 *  @author S. Koulouzis
 */
@implementation DRIP_COMMONSNS0Register

/**
 * The user name
 */
- (NSString *) user
{
  return _user;
}

/**
 * The user name
 */
- (void) setUser: (NSString *) newUser
{
  [newUser retain];
  [_user release];
  _user = newUser;
}

/**
 * The user password
 */
- (NSString *) pwd
{
  return _pwd;
}

/**
 * The user password
 */
- (void) setPwd: (NSString *) newPwd
{
  [newPwd retain];
  [_pwd release];
  _pwd = newPwd;
}

- (void) dealloc
{
  [self setUser: nil];
  [self setPwd: nil];
  [super dealloc];
}

//documentation inherited.
+ (id<EnunciateXML>) readFromXML: (NSData *) xml
{
  DRIP_COMMONSNS0Register *_dRIP_COMMONSNS0Register;
  xmlTextReaderPtr reader = xmlReaderForMemory([xml bytes], [xml length], NULL, NULL, 0);
  if (reader == NULL) {
    [NSException raise: @"XMLReadError"
                 format: @"Error instantiating an XML reader."];
    return nil;
  }

  _dRIP_COMMONSNS0Register = (DRIP_COMMONSNS0Register *) [DRIP_COMMONSNS0Register readXMLElement: reader];
  xmlFreeTextReader(reader); //free the reader
  return _dRIP_COMMONSNS0Register;
}

//documentation inherited.
- (NSData *) writeToXML
{
  xmlBufferPtr buf;
  xmlTextWriterPtr writer;
  int rc;
  NSData *data;

  buf = xmlBufferCreate();
  if (buf == NULL) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error creating an XML buffer."];
    return nil;
  }

  writer = xmlNewTextWriterMemory(buf, 0);
  if (writer == NULL) {
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error creating an XML writer."];
    return nil;
  }

  rc = xmlTextWriterStartDocument(writer, NULL, "utf-8", NULL);
  if (rc < 0) {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing XML start document."];
    return nil;
  }

  NS_DURING
  {
    [self writeXMLElement: writer];
  }
  NS_HANDLER
  {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [localException raise];
  }
  NS_ENDHANDLER

  rc = xmlTextWriterEndDocument(writer);
  if (rc < 0) {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing XML end document."];
    return nil;
  }

  xmlFreeTextWriter(writer);
  data = [NSData dataWithBytes: buf->content length: buf->use];
  xmlBufferFree(buf);
  return data;
}
@end /* implementation DRIP_COMMONSNS0Register */

/**
 * Internal, private interface for JAXB reading and writing.
 */
@interface DRIP_COMMONSNS0Register (JAXB) <JAXBReading, JAXBWriting, JAXBType, JAXBElement>

@end /*interface DRIP_COMMONSNS0Register (JAXB)*/

/**
 * Internal, private implementation for JAXB reading and writing.
 */
@implementation DRIP_COMMONSNS0Register (JAXB)

/**
 * Read an instance of DRIP_COMMONSNS0Register from an XML reader.
 *
 * @param reader The reader.
 * @return An instance of DRIP_COMMONSNS0Register defined by the XML reader.
 */
+ (id<JAXBType>) readXMLType: (xmlTextReaderPtr) reader
{
  DRIP_COMMONSNS0Register *_dRIP_COMMONSNS0Register = [[DRIP_COMMONSNS0Register alloc] init];
  NS_DURING
  {
    [_dRIP_COMMONSNS0Register initWithReader: reader];
  }
  NS_HANDLER
  {
    _dRIP_COMMONSNS0Register = nil;
    [localException raise];
  }
  NS_ENDHANDLER

  [_dRIP_COMMONSNS0Register autorelease];
  return _dRIP_COMMONSNS0Register;
}

/**
 * Initialize this instance of DRIP_COMMONSNS0Register according to
 * the XML being read from the reader.
 *
 * @param reader The reader.
 */
- (id) initWithReader: (xmlTextReaderPtr) reader
{
  return [super initWithReader: reader];
}

/**
 * Write the XML for this instance of DRIP_COMMONSNS0Register to the writer.
 * Note that since we're only writing the XML type,
 * No start/end element will be written.
 *
 * @param reader The reader.
 */
- (void) writeXMLType: (xmlTextWriterPtr) writer
{
  [super writeXMLType:writer];
}

/**
 * Reads a DRIP_COMMONSNS0Register from an XML reader. The element to be read is
 * "register".
 *
 * @param reader The XML reader.
 * @return The DRIP_COMMONSNS0Register.
 */
+ (id<JAXBElement>) readXMLElement: (xmlTextReaderPtr) reader {
  int status;
  DRIP_COMMONSNS0Register *_register = nil;

  if (xmlTextReaderNodeType(reader) != XML_READER_TYPE_ELEMENT) {
    status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
    if (status < 1) {
      [NSException raise: @"XMLReadError"
                   format: @"Error advancing the reader to start element register."];
    }
  }

  if (xmlStrcmp(BAD_CAST "register", xmlTextReaderConstLocalName(reader)) == 0
      && xmlTextReaderConstNamespaceUri(reader) == NULL) {
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read root element {}register.");
#endif
    _register = (DRIP_COMMONSNS0Register *)[DRIP_COMMONSNS0Register readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Successfully read root element {}register.");
#endif
  }
  else {
    if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
      [NSException raise: @"XMLReadError"
                   format: @"Unable to read DRIP_COMMONSNS0Register. Expected element register. Current element: {}%s", xmlTextReaderConstLocalName(reader)];
    }
    else {
      [NSException raise: @"XMLReadError"
                   format: @"Unable to read DRIP_COMMONSNS0Register. Expected element register. Current element: {%s}%s\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader)];
    }
  }

  return _register;
}

/**
 * Writes this DRIP_COMMONSNS0Register to XML under element name "register".
 * The namespace declarations for the element will be written.
 *
 * @param writer The XML writer.
 * @param _register The Register to write.
 * @return 1 if successful, 0 otherwise.
 */
- (void) writeXMLElement: (xmlTextWriterPtr) writer
{
  [self writeXMLElement: writer writeNamespaces: YES];
}

/**
 * Writes this DRIP_COMMONSNS0Register to an XML writer.
 *
 * @param writer The writer.
 * @param writeNs Whether to write the namespaces for this element to the xml writer.
 */
- (void) writeXMLElement: (xmlTextWriterPtr) writer writeNamespaces: (BOOL) writeNs
{
  int rc = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "register", NULL);
  if (rc < 0) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing start element {}register. XML writer status: %i\n", rc];
  }

#if DEBUG_ENUNCIATE > 1
  NSLog(@"writing type {}register for root element {}register...");
#endif
  [self writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
  NSLog(@"successfully wrote type {}register for root element {}register...");
#endif
  rc = xmlTextWriterEndElement(writer);
  if (rc < 0) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing end element {}register. XML writer status: %i\n", rc];
  }
}

//documentation inherited.
- (BOOL) readJAXBAttribute: (xmlTextReaderPtr) reader
{
  void *_child_accessor;

  if ([super readJAXBAttribute: reader]) {
    return YES;
  }

  return NO;
}

//documentation inherited.
- (BOOL) readJAXBValue: (xmlTextReaderPtr) reader
{
  return [super readJAXBValue: reader];
}

//documentation inherited.
- (BOOL) readJAXBChildElement: (xmlTextReaderPtr) reader
{
  id __child;
  void *_child_accessor;
  int status, depth;

  if ([super readJAXBChildElement: reader]) {
    return YES;
  }
  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "user", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setUser: __child];
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "pwd", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setPwd: __child];
    return YES;
  } //end "if choice"


  return NO;
}

//documentation inherited.
- (int) readUnknownJAXBChildElement: (xmlTextReaderPtr) reader
{
  return [super readUnknownJAXBChildElement: reader];
}

//documentation inherited.
- (void) readUnknownJAXBAttribute: (xmlTextReaderPtr) reader
{
  [super readUnknownJAXBAttribute: reader];
}

//documentation inherited.
- (void) writeJAXBAttributes: (xmlTextWriterPtr) writer
{
  int status;

  [super writeJAXBAttributes: writer];

}

//documentation inherited.
- (void) writeJAXBValue: (xmlTextWriterPtr) writer
{
  [super writeJAXBValue: writer];
}

/**
 * Method for writing the child elements.
 *
 * @param writer The writer.
 */
- (void) writeJAXBChildElements: (xmlTextWriterPtr) writer
{
  int status;
  id __item;
  id __item_copy;
  NSEnumerator *__enumerator;

  [super writeJAXBChildElements: writer];

  if ([self user]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "user", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}user."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}user...");
#endif
    [[self user] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}user...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}user."];
    }
  }
  if ([self pwd]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "pwd", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}pwd."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}pwd...");
#endif
    [[self pwd] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}pwd...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}pwd."];
    }
  }
}
@end /* implementation DRIP_COMMONSNS0Register (JAXB) */

#endif /* DEF_DRIP_COMMONSNS0Register_M */
#ifndef DEF_DRIP_COMMONSNS0Upload_M
#define DEF_DRIP_COMMONSNS0Upload_M

/**
 * 
 *  @author S. Koulouzis
 */
@implementation DRIP_COMMONSNS0Upload

/**
 * (no documentation provided)
 */
- (NSString *) user
{
  return _user;
}

/**
 * (no documentation provided)
 */
- (void) setUser: (NSString *) newUser
{
  [newUser retain];
  [_user release];
  _user = newUser;
}

/**
 * (no documentation provided)
 */
- (NSString *) pwd
{
  return _pwd;
}

/**
 * (no documentation provided)
 */
- (void) setPwd: (NSString *) newPwd
{
  [newPwd retain];
  [_pwd release];
  _pwd = newPwd;
}

/**
 * (no documentation provided)
 */
- (NSArray *) file
{
  return _file;
}

/**
 * (no documentation provided)
 */
- (void) setFile: (NSArray *) newFile
{
  [newFile retain];
  [_file release];
  _file = newFile;
}

- (void) dealloc
{
  [self setUser: nil];
  [self setPwd: nil];
  [self setFile: nil];
  [super dealloc];
}

//documentation inherited.
+ (id<EnunciateXML>) readFromXML: (NSData *) xml
{
  DRIP_COMMONSNS0Upload *_dRIP_COMMONSNS0Upload;
  xmlTextReaderPtr reader = xmlReaderForMemory([xml bytes], [xml length], NULL, NULL, 0);
  if (reader == NULL) {
    [NSException raise: @"XMLReadError"
                 format: @"Error instantiating an XML reader."];
    return nil;
  }

  _dRIP_COMMONSNS0Upload = (DRIP_COMMONSNS0Upload *) [DRIP_COMMONSNS0Upload readXMLElement: reader];
  xmlFreeTextReader(reader); //free the reader
  return _dRIP_COMMONSNS0Upload;
}

//documentation inherited.
- (NSData *) writeToXML
{
  xmlBufferPtr buf;
  xmlTextWriterPtr writer;
  int rc;
  NSData *data;

  buf = xmlBufferCreate();
  if (buf == NULL) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error creating an XML buffer."];
    return nil;
  }

  writer = xmlNewTextWriterMemory(buf, 0);
  if (writer == NULL) {
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error creating an XML writer."];
    return nil;
  }

  rc = xmlTextWriterStartDocument(writer, NULL, "utf-8", NULL);
  if (rc < 0) {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing XML start document."];
    return nil;
  }

  NS_DURING
  {
    [self writeXMLElement: writer];
  }
  NS_HANDLER
  {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [localException raise];
  }
  NS_ENDHANDLER

  rc = xmlTextWriterEndDocument(writer);
  if (rc < 0) {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing XML end document."];
    return nil;
  }

  xmlFreeTextWriter(writer);
  data = [NSData dataWithBytes: buf->content length: buf->use];
  xmlBufferFree(buf);
  return data;
}
@end /* implementation DRIP_COMMONSNS0Upload */

/**
 * Internal, private interface for JAXB reading and writing.
 */
@interface DRIP_COMMONSNS0Upload (JAXB) <JAXBReading, JAXBWriting, JAXBType, JAXBElement>

@end /*interface DRIP_COMMONSNS0Upload (JAXB)*/

/**
 * Internal, private implementation for JAXB reading and writing.
 */
@implementation DRIP_COMMONSNS0Upload (JAXB)

/**
 * Read an instance of DRIP_COMMONSNS0Upload from an XML reader.
 *
 * @param reader The reader.
 * @return An instance of DRIP_COMMONSNS0Upload defined by the XML reader.
 */
+ (id<JAXBType>) readXMLType: (xmlTextReaderPtr) reader
{
  DRIP_COMMONSNS0Upload *_dRIP_COMMONSNS0Upload = [[DRIP_COMMONSNS0Upload alloc] init];
  NS_DURING
  {
    [_dRIP_COMMONSNS0Upload initWithReader: reader];
  }
  NS_HANDLER
  {
    _dRIP_COMMONSNS0Upload = nil;
    [localException raise];
  }
  NS_ENDHANDLER

  [_dRIP_COMMONSNS0Upload autorelease];
  return _dRIP_COMMONSNS0Upload;
}

/**
 * Initialize this instance of DRIP_COMMONSNS0Upload according to
 * the XML being read from the reader.
 *
 * @param reader The reader.
 */
- (id) initWithReader: (xmlTextReaderPtr) reader
{
  return [super initWithReader: reader];
}

/**
 * Write the XML for this instance of DRIP_COMMONSNS0Upload to the writer.
 * Note that since we're only writing the XML type,
 * No start/end element will be written.
 *
 * @param reader The reader.
 */
- (void) writeXMLType: (xmlTextWriterPtr) writer
{
  [super writeXMLType:writer];
}

/**
 * Reads a DRIP_COMMONSNS0Upload from an XML reader. The element to be read is
 * "upload".
 *
 * @param reader The XML reader.
 * @return The DRIP_COMMONSNS0Upload.
 */
+ (id<JAXBElement>) readXMLElement: (xmlTextReaderPtr) reader {
  int status;
  DRIP_COMMONSNS0Upload *_upload = nil;

  if (xmlTextReaderNodeType(reader) != XML_READER_TYPE_ELEMENT) {
    status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
    if (status < 1) {
      [NSException raise: @"XMLReadError"
                   format: @"Error advancing the reader to start element upload."];
    }
  }

  if (xmlStrcmp(BAD_CAST "upload", xmlTextReaderConstLocalName(reader)) == 0
      && xmlTextReaderConstNamespaceUri(reader) == NULL) {
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read root element {}upload.");
#endif
    _upload = (DRIP_COMMONSNS0Upload *)[DRIP_COMMONSNS0Upload readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Successfully read root element {}upload.");
#endif
  }
  else {
    if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
      [NSException raise: @"XMLReadError"
                   format: @"Unable to read DRIP_COMMONSNS0Upload. Expected element upload. Current element: {}%s", xmlTextReaderConstLocalName(reader)];
    }
    else {
      [NSException raise: @"XMLReadError"
                   format: @"Unable to read DRIP_COMMONSNS0Upload. Expected element upload. Current element: {%s}%s\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader)];
    }
  }

  return _upload;
}

/**
 * Writes this DRIP_COMMONSNS0Upload to XML under element name "upload".
 * The namespace declarations for the element will be written.
 *
 * @param writer The XML writer.
 * @param _upload The Upload to write.
 * @return 1 if successful, 0 otherwise.
 */
- (void) writeXMLElement: (xmlTextWriterPtr) writer
{
  [self writeXMLElement: writer writeNamespaces: YES];
}

/**
 * Writes this DRIP_COMMONSNS0Upload to an XML writer.
 *
 * @param writer The writer.
 * @param writeNs Whether to write the namespaces for this element to the xml writer.
 */
- (void) writeXMLElement: (xmlTextWriterPtr) writer writeNamespaces: (BOOL) writeNs
{
  int rc = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "upload", NULL);
  if (rc < 0) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing start element {}upload. XML writer status: %i\n", rc];
  }

#if DEBUG_ENUNCIATE > 1
  NSLog(@"writing type {}upload for root element {}upload...");
#endif
  [self writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
  NSLog(@"successfully wrote type {}upload for root element {}upload...");
#endif
  rc = xmlTextWriterEndElement(writer);
  if (rc < 0) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing end element {}upload. XML writer status: %i\n", rc];
  }
}

//documentation inherited.
- (BOOL) readJAXBAttribute: (xmlTextReaderPtr) reader
{
  void *_child_accessor;

  if ([super readJAXBAttribute: reader]) {
    return YES;
  }

  return NO;
}

//documentation inherited.
- (BOOL) readJAXBValue: (xmlTextReaderPtr) reader
{
  return [super readJAXBValue: reader];
}

//documentation inherited.
- (BOOL) readJAXBChildElement: (xmlTextReaderPtr) reader
{
  id __child;
  void *_child_accessor;
  int status, depth;

  if ([super readJAXBChildElement: reader]) {
    return YES;
  }
  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "user", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setUser: __child];
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "pwd", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setPwd: __child];
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "file", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}file of type {}attribute.");
#endif

     __child = [DRIP_COMMONSNS0Attribute readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}file of type {}attribute.");
#endif

    if ([self file]) {
      [self setFile: [[self file] arrayByAddingObject: __child]];
    }
    else {
      [self setFile: [NSArray arrayWithObject: __child]];
    }
    return YES;
  } //end "if choice"


  return NO;
}

//documentation inherited.
- (int) readUnknownJAXBChildElement: (xmlTextReaderPtr) reader
{
  return [super readUnknownJAXBChildElement: reader];
}

//documentation inherited.
- (void) readUnknownJAXBAttribute: (xmlTextReaderPtr) reader
{
  [super readUnknownJAXBAttribute: reader];
}

//documentation inherited.
- (void) writeJAXBAttributes: (xmlTextWriterPtr) writer
{
  int status;

  [super writeJAXBAttributes: writer];

}

//documentation inherited.
- (void) writeJAXBValue: (xmlTextWriterPtr) writer
{
  [super writeJAXBValue: writer];
}

/**
 * Method for writing the child elements.
 *
 * @param writer The writer.
 */
- (void) writeJAXBChildElements: (xmlTextWriterPtr) writer
{
  int status;
  id __item;
  id __item_copy;
  NSEnumerator *__enumerator;

  [super writeJAXBChildElements: writer];

  if ([self user]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "user", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}user."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}user...");
#endif
    [[self user] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}user...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}user."];
    }
  }
  if ([self pwd]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "pwd", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}pwd."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}pwd...");
#endif
    [[self pwd] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}pwd...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}pwd."];
    }
  }
  if ([self file]) {
    __enumerator = [[self file] objectEnumerator];

    while ( (__item = [__enumerator nextObject]) ) {
      status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "file", NULL);
      if (status < 0) {
        [NSException raise: @"XMLWriteError"
                     format: @"Error writing start child element {}file."];
      }

#if DEBUG_ENUNCIATE > 1
      NSLog(@"writing element {}file...");
#endif
      [__item writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
      NSLog(@"successfully wrote element {}file...");
#endif

      status = xmlTextWriterEndElement(writer);
      if (status < 0) {
        [NSException raise: @"XMLWriteError"
                     format: @"Error writing end child element {}file."];
      }
    } //end item iterator.
  }
}
@end /* implementation DRIP_COMMONSNS0Upload (JAXB) */

#endif /* DEF_DRIP_COMMONSNS0Upload_M */
#ifndef DEF_DRIP_COMMONSNS0Result_M
#define DEF_DRIP_COMMONSNS0Result_M

/**
 * 
 *  @author S. Koulouzis
 */
@implementation DRIP_COMMONSNS0Result

/**
 * The status of the response
 */
- (NSString *) status
{
  return _status;
}

/**
 * The status of the response
 */
- (void) setStatus: (NSString *) newStatus
{
  [newStatus retain];
  [_status release];
  _status = newStatus;
}

/**
 * Not used. Not used. It's there for backwards compatibility.
 */
- (NSString *) info
{
  return _info;
}

/**
 * Not used. Not used. It's there for backwards compatibility.
 */
- (void) setInfo: (NSString *) newInfo
{
  [newInfo retain];
  [_info release];
  _info = newInfo;
}

/**
 * (no documentation provided)
 */
- (NSArray *) file
{
  return _file;
}

/**
 * (no documentation provided)
 */
- (void) setFile: (NSArray *) newFile
{
  [newFile retain];
  [_file release];
  _file = newFile;
}

- (void) dealloc
{
  [self setStatus: nil];
  [self setInfo: nil];
  [self setFile: nil];
  [super dealloc];
}

//documentation inherited.
+ (id<EnunciateXML>) readFromXML: (NSData *) xml
{
  DRIP_COMMONSNS0Result *_dRIP_COMMONSNS0Result;
  xmlTextReaderPtr reader = xmlReaderForMemory([xml bytes], [xml length], NULL, NULL, 0);
  if (reader == NULL) {
    [NSException raise: @"XMLReadError"
                 format: @"Error instantiating an XML reader."];
    return nil;
  }

  _dRIP_COMMONSNS0Result = (DRIP_COMMONSNS0Result *) [DRIP_COMMONSNS0Result readXMLElement: reader];
  xmlFreeTextReader(reader); //free the reader
  return _dRIP_COMMONSNS0Result;
}

//documentation inherited.
- (NSData *) writeToXML
{
  xmlBufferPtr buf;
  xmlTextWriterPtr writer;
  int rc;
  NSData *data;

  buf = xmlBufferCreate();
  if (buf == NULL) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error creating an XML buffer."];
    return nil;
  }

  writer = xmlNewTextWriterMemory(buf, 0);
  if (writer == NULL) {
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error creating an XML writer."];
    return nil;
  }

  rc = xmlTextWriterStartDocument(writer, NULL, "utf-8", NULL);
  if (rc < 0) {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing XML start document."];
    return nil;
  }

  NS_DURING
  {
    [self writeXMLElement: writer];
  }
  NS_HANDLER
  {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [localException raise];
  }
  NS_ENDHANDLER

  rc = xmlTextWriterEndDocument(writer);
  if (rc < 0) {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing XML end document."];
    return nil;
  }

  xmlFreeTextWriter(writer);
  data = [NSData dataWithBytes: buf->content length: buf->use];
  xmlBufferFree(buf);
  return data;
}
@end /* implementation DRIP_COMMONSNS0Result */

/**
 * Internal, private interface for JAXB reading and writing.
 */
@interface DRIP_COMMONSNS0Result (JAXB) <JAXBReading, JAXBWriting, JAXBType, JAXBElement>

@end /*interface DRIP_COMMONSNS0Result (JAXB)*/

/**
 * Internal, private implementation for JAXB reading and writing.
 */
@implementation DRIP_COMMONSNS0Result (JAXB)

/**
 * Read an instance of DRIP_COMMONSNS0Result from an XML reader.
 *
 * @param reader The reader.
 * @return An instance of DRIP_COMMONSNS0Result defined by the XML reader.
 */
+ (id<JAXBType>) readXMLType: (xmlTextReaderPtr) reader
{
  DRIP_COMMONSNS0Result *_dRIP_COMMONSNS0Result = [[DRIP_COMMONSNS0Result alloc] init];
  NS_DURING
  {
    [_dRIP_COMMONSNS0Result initWithReader: reader];
  }
  NS_HANDLER
  {
    _dRIP_COMMONSNS0Result = nil;
    [localException raise];
  }
  NS_ENDHANDLER

  [_dRIP_COMMONSNS0Result autorelease];
  return _dRIP_COMMONSNS0Result;
}

/**
 * Initialize this instance of DRIP_COMMONSNS0Result according to
 * the XML being read from the reader.
 *
 * @param reader The reader.
 */
- (id) initWithReader: (xmlTextReaderPtr) reader
{
  return [super initWithReader: reader];
}

/**
 * Write the XML for this instance of DRIP_COMMONSNS0Result to the writer.
 * Note that since we're only writing the XML type,
 * No start/end element will be written.
 *
 * @param reader The reader.
 */
- (void) writeXMLType: (xmlTextWriterPtr) writer
{
  [super writeXMLType:writer];
}

/**
 * Reads a DRIP_COMMONSNS0Result from an XML reader. The element to be read is
 * "result".
 *
 * @param reader The XML reader.
 * @return The DRIP_COMMONSNS0Result.
 */
+ (id<JAXBElement>) readXMLElement: (xmlTextReaderPtr) reader {
  int status;
  DRIP_COMMONSNS0Result *_result = nil;

  if (xmlTextReaderNodeType(reader) != XML_READER_TYPE_ELEMENT) {
    status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
    if (status < 1) {
      [NSException raise: @"XMLReadError"
                   format: @"Error advancing the reader to start element result."];
    }
  }

  if (xmlStrcmp(BAD_CAST "result", xmlTextReaderConstLocalName(reader)) == 0
      && xmlTextReaderConstNamespaceUri(reader) == NULL) {
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read root element {}result.");
#endif
    _result = (DRIP_COMMONSNS0Result *)[DRIP_COMMONSNS0Result readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Successfully read root element {}result.");
#endif
  }
  else {
    if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
      [NSException raise: @"XMLReadError"
                   format: @"Unable to read DRIP_COMMONSNS0Result. Expected element result. Current element: {}%s", xmlTextReaderConstLocalName(reader)];
    }
    else {
      [NSException raise: @"XMLReadError"
                   format: @"Unable to read DRIP_COMMONSNS0Result. Expected element result. Current element: {%s}%s\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader)];
    }
  }

  return _result;
}

/**
 * Writes this DRIP_COMMONSNS0Result to XML under element name "result".
 * The namespace declarations for the element will be written.
 *
 * @param writer The XML writer.
 * @param _result The Result to write.
 * @return 1 if successful, 0 otherwise.
 */
- (void) writeXMLElement: (xmlTextWriterPtr) writer
{
  [self writeXMLElement: writer writeNamespaces: YES];
}

/**
 * Writes this DRIP_COMMONSNS0Result to an XML writer.
 *
 * @param writer The writer.
 * @param writeNs Whether to write the namespaces for this element to the xml writer.
 */
- (void) writeXMLElement: (xmlTextWriterPtr) writer writeNamespaces: (BOOL) writeNs
{
  int rc = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "result", NULL);
  if (rc < 0) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing start element {}result. XML writer status: %i\n", rc];
  }

#if DEBUG_ENUNCIATE > 1
  NSLog(@"writing type {}result for root element {}result...");
#endif
  [self writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
  NSLog(@"successfully wrote type {}result for root element {}result...");
#endif
  rc = xmlTextWriterEndElement(writer);
  if (rc < 0) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing end element {}result. XML writer status: %i\n", rc];
  }
}

//documentation inherited.
- (BOOL) readJAXBAttribute: (xmlTextReaderPtr) reader
{
  void *_child_accessor;

  if ([super readJAXBAttribute: reader]) {
    return YES;
  }

  return NO;
}

//documentation inherited.
- (BOOL) readJAXBValue: (xmlTextReaderPtr) reader
{
  return [super readJAXBValue: reader];
}

//documentation inherited.
- (BOOL) readJAXBChildElement: (xmlTextReaderPtr) reader
{
  id __child;
  void *_child_accessor;
  int status, depth;

  if ([super readJAXBChildElement: reader]) {
    return YES;
  }
  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "status", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}status of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}status of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setStatus: __child];
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "info", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}info of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}info of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setInfo: __child];
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "file", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}file of type {}attribute.");
#endif

     __child = [DRIP_COMMONSNS0Attribute readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}file of type {}attribute.");
#endif

    if ([self file]) {
      [self setFile: [[self file] arrayByAddingObject: __child]];
    }
    else {
      [self setFile: [NSArray arrayWithObject: __child]];
    }
    return YES;
  } //end "if choice"


  return NO;
}

//documentation inherited.
- (int) readUnknownJAXBChildElement: (xmlTextReaderPtr) reader
{
  return [super readUnknownJAXBChildElement: reader];
}

//documentation inherited.
- (void) readUnknownJAXBAttribute: (xmlTextReaderPtr) reader
{
  [super readUnknownJAXBAttribute: reader];
}

//documentation inherited.
- (void) writeJAXBAttributes: (xmlTextWriterPtr) writer
{
  int status;

  [super writeJAXBAttributes: writer];

}

//documentation inherited.
- (void) writeJAXBValue: (xmlTextWriterPtr) writer
{
  [super writeJAXBValue: writer];
}

/**
 * Method for writing the child elements.
 *
 * @param writer The writer.
 */
- (void) writeJAXBChildElements: (xmlTextWriterPtr) writer
{
  int status;
  id __item;
  id __item_copy;
  NSEnumerator *__enumerator;

  [super writeJAXBChildElements: writer];

  if ([self status]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "status", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}status."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}status...");
#endif
    [[self status] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}status...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}status."];
    }
  }
  if ([self info]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "info", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}info."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}info...");
#endif
    [[self info] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}info...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}info."];
    }
  }
  if ([self file]) {
    __enumerator = [[self file] objectEnumerator];

    while ( (__item = [__enumerator nextObject]) ) {
      status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "file", NULL);
      if (status < 0) {
        [NSException raise: @"XMLWriteError"
                     format: @"Error writing start child element {}file."];
      }

#if DEBUG_ENUNCIATE > 1
      NSLog(@"writing element {}file...");
#endif
      [__item writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
      NSLog(@"successfully wrote element {}file...");
#endif

      status = xmlTextWriterEndElement(writer);
      if (status < 0) {
        [NSException raise: @"XMLWriteError"
                     format: @"Error writing end child element {}file."];
      }
    } //end item iterator.
  }
}
@end /* implementation DRIP_COMMONSNS0Result (JAXB) */

#endif /* DEF_DRIP_COMMONSNS0Result_M */
#ifndef DEF_DRIP_COMMONSNS0Plan_M
#define DEF_DRIP_COMMONSNS0Plan_M

/**
 * 
 *  This class represents a plan to be provided to the planner.
 * 
 *  @author S. Koulouzis
 */
@implementation DRIP_COMMONSNS0Plan

/**
 * Not used. It's only there for backwords compatibility
 */
- (NSString *) user
{
  return _user;
}

/**
 * Not used. It's only there for backwords compatibility
 */
- (void) setUser: (NSString *) newUser
{
  [newUser retain];
  [_user release];
  _user = newUser;
}

/**
 * Not used. It's only there for backwords compatibility
 */
- (NSString *) pwd
{
  return _pwd;
}

/**
 * Not used. It's only there for backwords compatibility
 */
- (void) setPwd: (NSString *) newPwd
{
  [newPwd retain];
  [_pwd release];
  _pwd = newPwd;
}

/**
 * The contents of the TOSCA description
 */
- (NSString *) file
{
  return _file;
}

/**
 * The contents of the TOSCA description
 */
- (void) setFile: (NSString *) newFile
{
  [newFile retain];
  [_file release];
  _file = newFile;
}

- (void) dealloc
{
  [self setUser: nil];
  [self setPwd: nil];
  [self setFile: nil];
  [super dealloc];
}

//documentation inherited.
+ (id<EnunciateXML>) readFromXML: (NSData *) xml
{
  DRIP_COMMONSNS0Plan *_dRIP_COMMONSNS0Plan;
  xmlTextReaderPtr reader = xmlReaderForMemory([xml bytes], [xml length], NULL, NULL, 0);
  if (reader == NULL) {
    [NSException raise: @"XMLReadError"
                 format: @"Error instantiating an XML reader."];
    return nil;
  }

  _dRIP_COMMONSNS0Plan = (DRIP_COMMONSNS0Plan *) [DRIP_COMMONSNS0Plan readXMLElement: reader];
  xmlFreeTextReader(reader); //free the reader
  return _dRIP_COMMONSNS0Plan;
}

//documentation inherited.
- (NSData *) writeToXML
{
  xmlBufferPtr buf;
  xmlTextWriterPtr writer;
  int rc;
  NSData *data;

  buf = xmlBufferCreate();
  if (buf == NULL) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error creating an XML buffer."];
    return nil;
  }

  writer = xmlNewTextWriterMemory(buf, 0);
  if (writer == NULL) {
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error creating an XML writer."];
    return nil;
  }

  rc = xmlTextWriterStartDocument(writer, NULL, "utf-8", NULL);
  if (rc < 0) {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing XML start document."];
    return nil;
  }

  NS_DURING
  {
    [self writeXMLElement: writer];
  }
  NS_HANDLER
  {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [localException raise];
  }
  NS_ENDHANDLER

  rc = xmlTextWriterEndDocument(writer);
  if (rc < 0) {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing XML end document."];
    return nil;
  }

  xmlFreeTextWriter(writer);
  data = [NSData dataWithBytes: buf->content length: buf->use];
  xmlBufferFree(buf);
  return data;
}
@end /* implementation DRIP_COMMONSNS0Plan */

/**
 * Internal, private interface for JAXB reading and writing.
 */
@interface DRIP_COMMONSNS0Plan (JAXB) <JAXBReading, JAXBWriting, JAXBType, JAXBElement>

@end /*interface DRIP_COMMONSNS0Plan (JAXB)*/

/**
 * Internal, private implementation for JAXB reading and writing.
 */
@implementation DRIP_COMMONSNS0Plan (JAXB)

/**
 * Read an instance of DRIP_COMMONSNS0Plan from an XML reader.
 *
 * @param reader The reader.
 * @return An instance of DRIP_COMMONSNS0Plan defined by the XML reader.
 */
+ (id<JAXBType>) readXMLType: (xmlTextReaderPtr) reader
{
  DRIP_COMMONSNS0Plan *_dRIP_COMMONSNS0Plan = [[DRIP_COMMONSNS0Plan alloc] init];
  NS_DURING
  {
    [_dRIP_COMMONSNS0Plan initWithReader: reader];
  }
  NS_HANDLER
  {
    _dRIP_COMMONSNS0Plan = nil;
    [localException raise];
  }
  NS_ENDHANDLER

  [_dRIP_COMMONSNS0Plan autorelease];
  return _dRIP_COMMONSNS0Plan;
}

/**
 * Initialize this instance of DRIP_COMMONSNS0Plan according to
 * the XML being read from the reader.
 *
 * @param reader The reader.
 */
- (id) initWithReader: (xmlTextReaderPtr) reader
{
  return [super initWithReader: reader];
}

/**
 * Write the XML for this instance of DRIP_COMMONSNS0Plan to the writer.
 * Note that since we're only writing the XML type,
 * No start/end element will be written.
 *
 * @param reader The reader.
 */
- (void) writeXMLType: (xmlTextWriterPtr) writer
{
  [super writeXMLType:writer];
}

/**
 * Reads a DRIP_COMMONSNS0Plan from an XML reader. The element to be read is
 * "plan".
 *
 * @param reader The XML reader.
 * @return The DRIP_COMMONSNS0Plan.
 */
+ (id<JAXBElement>) readXMLElement: (xmlTextReaderPtr) reader {
  int status;
  DRIP_COMMONSNS0Plan *_plan = nil;

  if (xmlTextReaderNodeType(reader) != XML_READER_TYPE_ELEMENT) {
    status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
    if (status < 1) {
      [NSException raise: @"XMLReadError"
                   format: @"Error advancing the reader to start element plan."];
    }
  }

  if (xmlStrcmp(BAD_CAST "plan", xmlTextReaderConstLocalName(reader)) == 0
      && xmlTextReaderConstNamespaceUri(reader) == NULL) {
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read root element {}plan.");
#endif
    _plan = (DRIP_COMMONSNS0Plan *)[DRIP_COMMONSNS0Plan readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Successfully read root element {}plan.");
#endif
  }
  else {
    if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
      [NSException raise: @"XMLReadError"
                   format: @"Unable to read DRIP_COMMONSNS0Plan. Expected element plan. Current element: {}%s", xmlTextReaderConstLocalName(reader)];
    }
    else {
      [NSException raise: @"XMLReadError"
                   format: @"Unable to read DRIP_COMMONSNS0Plan. Expected element plan. Current element: {%s}%s\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader)];
    }
  }

  return _plan;
}

/**
 * Writes this DRIP_COMMONSNS0Plan to XML under element name "plan".
 * The namespace declarations for the element will be written.
 *
 * @param writer The XML writer.
 * @param _plan The Plan to write.
 * @return 1 if successful, 0 otherwise.
 */
- (void) writeXMLElement: (xmlTextWriterPtr) writer
{
  [self writeXMLElement: writer writeNamespaces: YES];
}

/**
 * Writes this DRIP_COMMONSNS0Plan to an XML writer.
 *
 * @param writer The writer.
 * @param writeNs Whether to write the namespaces for this element to the xml writer.
 */
- (void) writeXMLElement: (xmlTextWriterPtr) writer writeNamespaces: (BOOL) writeNs
{
  int rc = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "plan", NULL);
  if (rc < 0) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing start element {}plan. XML writer status: %i\n", rc];
  }

#if DEBUG_ENUNCIATE > 1
  NSLog(@"writing type {}plan for root element {}plan...");
#endif
  [self writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
  NSLog(@"successfully wrote type {}plan for root element {}plan...");
#endif
  rc = xmlTextWriterEndElement(writer);
  if (rc < 0) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing end element {}plan. XML writer status: %i\n", rc];
  }
}

//documentation inherited.
- (BOOL) readJAXBAttribute: (xmlTextReaderPtr) reader
{
  void *_child_accessor;

  if ([super readJAXBAttribute: reader]) {
    return YES;
  }

  return NO;
}

//documentation inherited.
- (BOOL) readJAXBValue: (xmlTextReaderPtr) reader
{
  return [super readJAXBValue: reader];
}

//documentation inherited.
- (BOOL) readJAXBChildElement: (xmlTextReaderPtr) reader
{
  id __child;
  void *_child_accessor;
  int status, depth;

  if ([super readJAXBChildElement: reader]) {
    return YES;
  }
  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "user", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}user of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setUser: __child];
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "pwd", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}pwd of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setPwd: __child];
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "file", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}file of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}file of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setFile: __child];
    return YES;
  } //end "if choice"


  return NO;
}

//documentation inherited.
- (int) readUnknownJAXBChildElement: (xmlTextReaderPtr) reader
{
  return [super readUnknownJAXBChildElement: reader];
}

//documentation inherited.
- (void) readUnknownJAXBAttribute: (xmlTextReaderPtr) reader
{
  [super readUnknownJAXBAttribute: reader];
}

//documentation inherited.
- (void) writeJAXBAttributes: (xmlTextWriterPtr) writer
{
  int status;

  [super writeJAXBAttributes: writer];

}

//documentation inherited.
- (void) writeJAXBValue: (xmlTextWriterPtr) writer
{
  [super writeJAXBValue: writer];
}

/**
 * Method for writing the child elements.
 *
 * @param writer The writer.
 */
- (void) writeJAXBChildElements: (xmlTextWriterPtr) writer
{
  int status;
  id __item;
  id __item_copy;
  NSEnumerator *__enumerator;

  [super writeJAXBChildElements: writer];

  if ([self user]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "user", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}user."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}user...");
#endif
    [[self user] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}user...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}user."];
    }
  }
  if ([self pwd]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "pwd", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}pwd."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}pwd...");
#endif
    [[self pwd] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}pwd...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}pwd."];
    }
  }
  if ([self file]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "file", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}file."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}file...");
#endif
    [[self file] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}file...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}file."];
    }
  }
}
@end /* implementation DRIP_COMMONSNS0Plan (JAXB) */

#endif /* DEF_DRIP_COMMONSNS0Plan_M */
#ifndef DEF_DRIP_COMMONSNS0Attribute_M
#define DEF_DRIP_COMMONSNS0Attribute_M

/**
 * 
 *  @author S. Koulouzis
 */
@implementation DRIP_COMMONSNS0Attribute

/**
 * Name of the file/public key.
 */
- (NSString *) name
{
  return _name;
}

/**
 * Name of the file/public key.
 */
- (void) setName: (NSString *) newName
{
  [newName retain];
  [_name release];
  _name = newName;
}

/**
 * There are two levels of description files for topologies designed by users.
 * If the level attribute for the element file is 1, then this file is the top-level description,
 * which defines how the sub-topologies are connected to each other.
 * If the level attribute is 0, then the file is the low-level description,
 * which describes the topology in one data center in detail.
 * On the other hand, the name of low-level description file must be the
 * sub-topology name appeared in the high-level description file. (For example, here should be zh_a and zh_b.)
 */
- (NSString *) level
{
  return _level;
}

/**
 * There are two levels of description files for topologies designed by users.
 * If the level attribute for the element file is 1, then this file is the top-level description,
 * which defines how the sub-topologies are connected to each other.
 * If the level attribute is 0, then the file is the low-level description,
 * which describes the topology in one data center in detail.
 * On the other hand, the name of low-level description file must be the
 * sub-topology name appeared in the high-level description file. (For example, here should be zh_a and zh_b.)
 */
- (void) setLevel: (NSString *) newLevel
{
  [newLevel retain];
  [_level release];
  _level = newLevel;
}

/**
 * (no documentation provided)
 */
- (NSString *) content
{
  return _content;
}

/**
 * (no documentation provided)
 */
- (void) setContent: (NSString *) newContent
{
  [newContent retain];
  [_content release];
  _content = newContent;
}

- (void) dealloc
{
  [self setName: nil];
  [self setLevel: nil];
  [self setContent: nil];
  [super dealloc];
}
@end /* implementation DRIP_COMMONSNS0Attribute */

/**
 * Internal, private interface for JAXB reading and writing.
 */
@interface DRIP_COMMONSNS0Attribute (JAXB) <JAXBReading, JAXBWriting, JAXBType>

@end /*interface DRIP_COMMONSNS0Attribute (JAXB)*/

/**
 * Internal, private implementation for JAXB reading and writing.
 */
@implementation DRIP_COMMONSNS0Attribute (JAXB)

/**
 * Read an instance of DRIP_COMMONSNS0Attribute from an XML reader.
 *
 * @param reader The reader.
 * @return An instance of DRIP_COMMONSNS0Attribute defined by the XML reader.
 */
+ (id<JAXBType>) readXMLType: (xmlTextReaderPtr) reader
{
  DRIP_COMMONSNS0Attribute *_dRIP_COMMONSNS0Attribute = [[DRIP_COMMONSNS0Attribute alloc] init];
  NS_DURING
  {
    [_dRIP_COMMONSNS0Attribute initWithReader: reader];
  }
  NS_HANDLER
  {
    _dRIP_COMMONSNS0Attribute = nil;
    [localException raise];
  }
  NS_ENDHANDLER

  [_dRIP_COMMONSNS0Attribute autorelease];
  return _dRIP_COMMONSNS0Attribute;
}

/**
 * Initialize this instance of DRIP_COMMONSNS0Attribute according to
 * the XML being read from the reader.
 *
 * @param reader The reader.
 */
- (id) initWithReader: (xmlTextReaderPtr) reader
{
  return [super initWithReader: reader];
}

/**
 * Write the XML for this instance of DRIP_COMMONSNS0Attribute to the writer.
 * Note that since we're only writing the XML type,
 * No start/end element will be written.
 *
 * @param reader The reader.
 */
- (void) writeXMLType: (xmlTextWriterPtr) writer
{
  [super writeXMLType:writer];
}

//documentation inherited.
- (BOOL) readJAXBAttribute: (xmlTextReaderPtr) reader
{
  void *_child_accessor;

  if ([super readJAXBAttribute: reader]) {
    return YES;
  }

  if ((xmlStrcmp(BAD_CAST "name", xmlTextReaderConstLocalName(reader)) == 0) && (xmlTextReaderConstNamespaceUri(reader) == NULL)) {
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read attribute {}name...");
#endif
    [self setName: (NSString*) [NSString readXMLType: reader]];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read attribute {}name...");
#endif
    return YES;
  }

  if ((xmlStrcmp(BAD_CAST "level", xmlTextReaderConstLocalName(reader)) == 0) && (xmlTextReaderConstNamespaceUri(reader) == NULL)) {
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read attribute {}level...");
#endif
    [self setLevel: (NSString*) [NSString readXMLType: reader]];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read attribute {}level...");
#endif
    return YES;
  }

  return NO;
}

//documentation inherited.
- (BOOL) readJAXBValue: (xmlTextReaderPtr) reader
{

#if DEBUG_ENUNCIATE > 1
  NSLog(@"Attempting to read element value...");
#endif
  if (xmlTextReaderIsEmptyElement(reader) == 0) {
    [self setContent: (NSString *) [NSString readXMLType: reader]];
  }
  else {
    [self setContent: @""];
  }
#if DEBUG_ENUNCIATE > 1
  NSLog(@"successfully read element value...");
#endif

  return YES;
}
//documentation inherited.
- (BOOL) readJAXBChildElement: (xmlTextReaderPtr) reader
{
  return [super readJAXBChildElement: reader];
}

//documentation inherited.
- (int) readUnknownJAXBChildElement: (xmlTextReaderPtr) reader
{
  return [super readUnknownJAXBChildElement: reader];
}

//documentation inherited.
- (void) readUnknownJAXBAttribute: (xmlTextReaderPtr) reader
{
  [super readUnknownJAXBAttribute: reader];
}

//documentation inherited.
- (void) writeJAXBAttributes: (xmlTextWriterPtr) writer
{
  int status;

  [super writeJAXBAttributes: writer];

  if ([self name]) {

    status = xmlTextWriterStartAttributeNS(writer, NULL, BAD_CAST "name", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start attribute {}name."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing attribute {}name...");
#endif
    [[self name] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote attribute {}name...");
#endif

    status = xmlTextWriterEndAttribute(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end attribute {}name."];
    }
  }
  if ([self level]) {

    status = xmlTextWriterStartAttributeNS(writer, NULL, BAD_CAST "level", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start attribute {}level."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing attribute {}level...");
#endif
    [[self level] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote attribute {}level...");
#endif

    status = xmlTextWriterEndAttribute(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end attribute {}level."];
    }
  }
}

//documentation inherited.
- (void) writeJAXBValue: (xmlTextWriterPtr) writer
{
#if DEBUG_ENUNCIATE > 1
  NSLog(@"writing element value...");
#endif
  [[self content] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
  NSLog(@"successfully wrote element value...");
#endif
}

/**
 * Method for writing the child elements.
 *
 * @param writer The writer.
 */
- (void) writeJAXBChildElements: (xmlTextWriterPtr) writer
{
  [super writeJAXBChildElements: writer];
}
@end /* implementation DRIP_COMMONSNS0Attribute (JAXB) */

#endif /* DEF_DRIP_COMMONSNS0Attribute_M */
#ifndef DEF_DRIP_COMMONSNS0Deploy_M
#define DEF_DRIP_COMMONSNS0Deploy_M

/**
 * 
 *  @author S. Koulouzis
 */
@implementation DRIP_COMMONSNS0Deploy

- (void) dealloc
{
  [super dealloc];
}

//documentation inherited.
+ (id<EnunciateXML>) readFromXML: (NSData *) xml
{
  DRIP_COMMONSNS0Deploy *_dRIP_COMMONSNS0Deploy;
  xmlTextReaderPtr reader = xmlReaderForMemory([xml bytes], [xml length], NULL, NULL, 0);
  if (reader == NULL) {
    [NSException raise: @"XMLReadError"
                 format: @"Error instantiating an XML reader."];
    return nil;
  }

  _dRIP_COMMONSNS0Deploy = (DRIP_COMMONSNS0Deploy *) [DRIP_COMMONSNS0Deploy readXMLElement: reader];
  xmlFreeTextReader(reader); //free the reader
  return _dRIP_COMMONSNS0Deploy;
}

//documentation inherited.
- (NSData *) writeToXML
{
  xmlBufferPtr buf;
  xmlTextWriterPtr writer;
  int rc;
  NSData *data;

  buf = xmlBufferCreate();
  if (buf == NULL) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error creating an XML buffer."];
    return nil;
  }

  writer = xmlNewTextWriterMemory(buf, 0);
  if (writer == NULL) {
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error creating an XML writer."];
    return nil;
  }

  rc = xmlTextWriterStartDocument(writer, NULL, "utf-8", NULL);
  if (rc < 0) {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing XML start document."];
    return nil;
  }

  NS_DURING
  {
    [self writeXMLElement: writer];
  }
  NS_HANDLER
  {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [localException raise];
  }
  NS_ENDHANDLER

  rc = xmlTextWriterEndDocument(writer);
  if (rc < 0) {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing XML end document."];
    return nil;
  }

  xmlFreeTextWriter(writer);
  data = [NSData dataWithBytes: buf->content length: buf->use];
  xmlBufferFree(buf);
  return data;
}
@end /* implementation DRIP_COMMONSNS0Deploy */

/**
 * Internal, private interface for JAXB reading and writing.
 */
@interface DRIP_COMMONSNS0Deploy (JAXB) <JAXBReading, JAXBWriting, JAXBType, JAXBElement>

@end /*interface DRIP_COMMONSNS0Deploy (JAXB)*/

/**
 * Internal, private implementation for JAXB reading and writing.
 */
@implementation DRIP_COMMONSNS0Deploy (JAXB)

/**
 * Read an instance of DRIP_COMMONSNS0Deploy from an XML reader.
 *
 * @param reader The reader.
 * @return An instance of DRIP_COMMONSNS0Deploy defined by the XML reader.
 */
+ (id<JAXBType>) readXMLType: (xmlTextReaderPtr) reader
{
  DRIP_COMMONSNS0Deploy *_dRIP_COMMONSNS0Deploy = [[DRIP_COMMONSNS0Deploy alloc] init];
  NS_DURING
  {
    [_dRIP_COMMONSNS0Deploy initWithReader: reader];
  }
  NS_HANDLER
  {
    _dRIP_COMMONSNS0Deploy = nil;
    [localException raise];
  }
  NS_ENDHANDLER

  [_dRIP_COMMONSNS0Deploy autorelease];
  return _dRIP_COMMONSNS0Deploy;
}

/**
 * Initialize this instance of DRIP_COMMONSNS0Deploy according to
 * the XML being read from the reader.
 *
 * @param reader The reader.
 */
- (id) initWithReader: (xmlTextReaderPtr) reader
{
  return [super initWithReader: reader];
}

/**
 * Write the XML for this instance of DRIP_COMMONSNS0Deploy to the writer.
 * Note that since we're only writing the XML type,
 * No start/end element will be written.
 *
 * @param reader The reader.
 */
- (void) writeXMLType: (xmlTextWriterPtr) writer
{
  [super writeXMLType:writer];
}

/**
 * Reads a DRIP_COMMONSNS0Deploy from an XML reader. The element to be read is
 * "deploy".
 *
 * @param reader The XML reader.
 * @return The DRIP_COMMONSNS0Deploy.
 */
+ (id<JAXBElement>) readXMLElement: (xmlTextReaderPtr) reader {
  int status;
  DRIP_COMMONSNS0Deploy *_deploy = nil;

  if (xmlTextReaderNodeType(reader) != XML_READER_TYPE_ELEMENT) {
    status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
    if (status < 1) {
      [NSException raise: @"XMLReadError"
                   format: @"Error advancing the reader to start element deploy."];
    }
  }

  if (xmlStrcmp(BAD_CAST "deploy", xmlTextReaderConstLocalName(reader)) == 0
      && xmlTextReaderConstNamespaceUri(reader) == NULL) {
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read root element {}deploy.");
#endif
    _deploy = (DRIP_COMMONSNS0Deploy *)[DRIP_COMMONSNS0Deploy readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Successfully read root element {}deploy.");
#endif
  }
  else {
    if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
      [NSException raise: @"XMLReadError"
                   format: @"Unable to read DRIP_COMMONSNS0Deploy. Expected element deploy. Current element: {}%s", xmlTextReaderConstLocalName(reader)];
    }
    else {
      [NSException raise: @"XMLReadError"
                   format: @"Unable to read DRIP_COMMONSNS0Deploy. Expected element deploy. Current element: {%s}%s\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader)];
    }
  }

  return _deploy;
}

/**
 * Writes this DRIP_COMMONSNS0Deploy to XML under element name "deploy".
 * The namespace declarations for the element will be written.
 *
 * @param writer The XML writer.
 * @param _deploy The Deploy to write.
 * @return 1 if successful, 0 otherwise.
 */
- (void) writeXMLElement: (xmlTextWriterPtr) writer
{
  [self writeXMLElement: writer writeNamespaces: YES];
}

/**
 * Writes this DRIP_COMMONSNS0Deploy to an XML writer.
 *
 * @param writer The writer.
 * @param writeNs Whether to write the namespaces for this element to the xml writer.
 */
- (void) writeXMLElement: (xmlTextWriterPtr) writer writeNamespaces: (BOOL) writeNs
{
  int rc = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "deploy", NULL);
  if (rc < 0) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing start element {}deploy. XML writer status: %i\n", rc];
  }

#if DEBUG_ENUNCIATE > 1
  NSLog(@"writing type {}deploy for root element {}deploy...");
#endif
  [self writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
  NSLog(@"successfully wrote type {}deploy for root element {}deploy...");
#endif
  rc = xmlTextWriterEndElement(writer);
  if (rc < 0) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing end element {}deploy. XML writer status: %i\n", rc];
  }
}

//documentation inherited.
- (BOOL) readJAXBAttribute: (xmlTextReaderPtr) reader
{
  void *_child_accessor;

  if ([super readJAXBAttribute: reader]) {
    return YES;
  }

  return NO;
}

//documentation inherited.
- (BOOL) readJAXBValue: (xmlTextReaderPtr) reader
{
  return [super readJAXBValue: reader];
}

//documentation inherited.
- (BOOL) readJAXBChildElement: (xmlTextReaderPtr) reader
{
  id __child;
  void *_child_accessor;
  int status, depth;

  if ([super readJAXBChildElement: reader]) {
    return YES;
  }

  return NO;
}

//documentation inherited.
- (int) readUnknownJAXBChildElement: (xmlTextReaderPtr) reader
{
  return [super readUnknownJAXBChildElement: reader];
}

//documentation inherited.
- (void) readUnknownJAXBAttribute: (xmlTextReaderPtr) reader
{
  [super readUnknownJAXBAttribute: reader];
}

//documentation inherited.
- (void) writeJAXBAttributes: (xmlTextWriterPtr) writer
{
  int status;

  [super writeJAXBAttributes: writer];

}

//documentation inherited.
- (void) writeJAXBValue: (xmlTextWriterPtr) writer
{
  [super writeJAXBValue: writer];
}

/**
 * Method for writing the child elements.
 *
 * @param writer The writer.
 */
- (void) writeJAXBChildElements: (xmlTextWriterPtr) writer
{
  int status;
  id __item;
  id __item_copy;
  NSEnumerator *__enumerator;

  [super writeJAXBChildElements: writer];

}
@end /* implementation DRIP_COMMONSNS0Deploy (JAXB) */

#endif /* DEF_DRIP_COMMONSNS0Deploy_M */
#ifndef DEF_DRIP_COMMONSNS0ConfUserKey_M
#define DEF_DRIP_COMMONSNS0ConfUserKey_M

/**
 * 
 *  @author S. Koulouzis
 */
@implementation DRIP_COMMONSNS0ConfUserKey

/**
 * (no documentation provided)
 */
- (NSArray *) file
{
  return _file;
}

/**
 * (no documentation provided)
 */
- (void) setFile: (NSArray *) newFile
{
  [newFile retain];
  [_file release];
  _file = newFile;
}

- (void) dealloc
{
  [self setFile: nil];
  [super dealloc];
}

//documentation inherited.
+ (id<EnunciateXML>) readFromXML: (NSData *) xml
{
  DRIP_COMMONSNS0ConfUserKey *_dRIP_COMMONSNS0ConfUserKey;
  xmlTextReaderPtr reader = xmlReaderForMemory([xml bytes], [xml length], NULL, NULL, 0);
  if (reader == NULL) {
    [NSException raise: @"XMLReadError"
                 format: @"Error instantiating an XML reader."];
    return nil;
  }

  _dRIP_COMMONSNS0ConfUserKey = (DRIP_COMMONSNS0ConfUserKey *) [DRIP_COMMONSNS0ConfUserKey readXMLElement: reader];
  xmlFreeTextReader(reader); //free the reader
  return _dRIP_COMMONSNS0ConfUserKey;
}

//documentation inherited.
- (NSData *) writeToXML
{
  xmlBufferPtr buf;
  xmlTextWriterPtr writer;
  int rc;
  NSData *data;

  buf = xmlBufferCreate();
  if (buf == NULL) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error creating an XML buffer."];
    return nil;
  }

  writer = xmlNewTextWriterMemory(buf, 0);
  if (writer == NULL) {
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error creating an XML writer."];
    return nil;
  }

  rc = xmlTextWriterStartDocument(writer, NULL, "utf-8", NULL);
  if (rc < 0) {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing XML start document."];
    return nil;
  }

  NS_DURING
  {
    [self writeXMLElement: writer];
  }
  NS_HANDLER
  {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [localException raise];
  }
  NS_ENDHANDLER

  rc = xmlTextWriterEndDocument(writer);
  if (rc < 0) {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing XML end document."];
    return nil;
  }

  xmlFreeTextWriter(writer);
  data = [NSData dataWithBytes: buf->content length: buf->use];
  xmlBufferFree(buf);
  return data;
}
@end /* implementation DRIP_COMMONSNS0ConfUserKey */

/**
 * Internal, private interface for JAXB reading and writing.
 */
@interface DRIP_COMMONSNS0ConfUserKey (JAXB) <JAXBReading, JAXBWriting, JAXBType, JAXBElement>

@end /*interface DRIP_COMMONSNS0ConfUserKey (JAXB)*/

/**
 * Internal, private implementation for JAXB reading and writing.
 */
@implementation DRIP_COMMONSNS0ConfUserKey (JAXB)

/**
 * Read an instance of DRIP_COMMONSNS0ConfUserKey from an XML reader.
 *
 * @param reader The reader.
 * @return An instance of DRIP_COMMONSNS0ConfUserKey defined by the XML reader.
 */
+ (id<JAXBType>) readXMLType: (xmlTextReaderPtr) reader
{
  DRIP_COMMONSNS0ConfUserKey *_dRIP_COMMONSNS0ConfUserKey = [[DRIP_COMMONSNS0ConfUserKey alloc] init];
  NS_DURING
  {
    [_dRIP_COMMONSNS0ConfUserKey initWithReader: reader];
  }
  NS_HANDLER
  {
    _dRIP_COMMONSNS0ConfUserKey = nil;
    [localException raise];
  }
  NS_ENDHANDLER

  [_dRIP_COMMONSNS0ConfUserKey autorelease];
  return _dRIP_COMMONSNS0ConfUserKey;
}

/**
 * Initialize this instance of DRIP_COMMONSNS0ConfUserKey according to
 * the XML being read from the reader.
 *
 * @param reader The reader.
 */
- (id) initWithReader: (xmlTextReaderPtr) reader
{
  return [super initWithReader: reader];
}

/**
 * Write the XML for this instance of DRIP_COMMONSNS0ConfUserKey to the writer.
 * Note that since we're only writing the XML type,
 * No start/end element will be written.
 *
 * @param reader The reader.
 */
- (void) writeXMLType: (xmlTextWriterPtr) writer
{
  [super writeXMLType:writer];
}

/**
 * Reads a DRIP_COMMONSNS0ConfUserKey from an XML reader. The element to be read is
 * "confUserKey".
 *
 * @param reader The XML reader.
 * @return The DRIP_COMMONSNS0ConfUserKey.
 */
+ (id<JAXBElement>) readXMLElement: (xmlTextReaderPtr) reader {
  int status;
  DRIP_COMMONSNS0ConfUserKey *_confUserKey = nil;

  if (xmlTextReaderNodeType(reader) != XML_READER_TYPE_ELEMENT) {
    status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
    if (status < 1) {
      [NSException raise: @"XMLReadError"
                   format: @"Error advancing the reader to start element confUserKey."];
    }
  }

  if (xmlStrcmp(BAD_CAST "confUserKey", xmlTextReaderConstLocalName(reader)) == 0
      && xmlTextReaderConstNamespaceUri(reader) == NULL) {
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read root element {}confUserKey.");
#endif
    _confUserKey = (DRIP_COMMONSNS0ConfUserKey *)[DRIP_COMMONSNS0ConfUserKey readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Successfully read root element {}confUserKey.");
#endif
  }
  else {
    if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
      [NSException raise: @"XMLReadError"
                   format: @"Unable to read DRIP_COMMONSNS0ConfUserKey. Expected element confUserKey. Current element: {}%s", xmlTextReaderConstLocalName(reader)];
    }
    else {
      [NSException raise: @"XMLReadError"
                   format: @"Unable to read DRIP_COMMONSNS0ConfUserKey. Expected element confUserKey. Current element: {%s}%s\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader)];
    }
  }

  return _confUserKey;
}

/**
 * Writes this DRIP_COMMONSNS0ConfUserKey to XML under element name "confUserKey".
 * The namespace declarations for the element will be written.
 *
 * @param writer The XML writer.
 * @param _confUserKey The ConfUserKey to write.
 * @return 1 if successful, 0 otherwise.
 */
- (void) writeXMLElement: (xmlTextWriterPtr) writer
{
  [self writeXMLElement: writer writeNamespaces: YES];
}

/**
 * Writes this DRIP_COMMONSNS0ConfUserKey to an XML writer.
 *
 * @param writer The writer.
 * @param writeNs Whether to write the namespaces for this element to the xml writer.
 */
- (void) writeXMLElement: (xmlTextWriterPtr) writer writeNamespaces: (BOOL) writeNs
{
  int rc = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "confUserKey", NULL);
  if (rc < 0) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing start element {}confUserKey. XML writer status: %i\n", rc];
  }

#if DEBUG_ENUNCIATE > 1
  NSLog(@"writing type {}confUserKey for root element {}confUserKey...");
#endif
  [self writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
  NSLog(@"successfully wrote type {}confUserKey for root element {}confUserKey...");
#endif
  rc = xmlTextWriterEndElement(writer);
  if (rc < 0) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing end element {}confUserKey. XML writer status: %i\n", rc];
  }
}

//documentation inherited.
- (BOOL) readJAXBAttribute: (xmlTextReaderPtr) reader
{
  void *_child_accessor;

  if ([super readJAXBAttribute: reader]) {
    return YES;
  }

  return NO;
}

//documentation inherited.
- (BOOL) readJAXBValue: (xmlTextReaderPtr) reader
{
  return [super readJAXBValue: reader];
}

//documentation inherited.
- (BOOL) readJAXBChildElement: (xmlTextReaderPtr) reader
{
  id __child;
  void *_child_accessor;
  int status, depth;

  if ([super readJAXBChildElement: reader]) {
    return YES;
  }
  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "userKey", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}userKey of type {}attribute.");
#endif

     __child = [DRIP_COMMONSNS0Attribute readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}userKey of type {}attribute.");
#endif

    if ([self file]) {
      [self setFile: [[self file] arrayByAddingObject: __child]];
    }
    else {
      [self setFile: [NSArray arrayWithObject: __child]];
    }
    return YES;
  } //end "if choice"


  return NO;
}

//documentation inherited.
- (int) readUnknownJAXBChildElement: (xmlTextReaderPtr) reader
{
  return [super readUnknownJAXBChildElement: reader];
}

//documentation inherited.
- (void) readUnknownJAXBAttribute: (xmlTextReaderPtr) reader
{
  [super readUnknownJAXBAttribute: reader];
}

//documentation inherited.
- (void) writeJAXBAttributes: (xmlTextWriterPtr) writer
{
  int status;

  [super writeJAXBAttributes: writer];

}

//documentation inherited.
- (void) writeJAXBValue: (xmlTextWriterPtr) writer
{
  [super writeJAXBValue: writer];
}

/**
 * Method for writing the child elements.
 *
 * @param writer The writer.
 */
- (void) writeJAXBChildElements: (xmlTextWriterPtr) writer
{
  int status;
  id __item;
  id __item_copy;
  NSEnumerator *__enumerator;

  [super writeJAXBChildElements: writer];

  if ([self file]) {
    __enumerator = [[self file] objectEnumerator];

    while ( (__item = [__enumerator nextObject]) ) {
      status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "userKey", NULL);
      if (status < 0) {
        [NSException raise: @"XMLWriteError"
                     format: @"Error writing start child element {}userKey."];
      }

#if DEBUG_ENUNCIATE > 1
      NSLog(@"writing element {}userKey...");
#endif
      [__item writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
      NSLog(@"successfully wrote element {}userKey...");
#endif

      status = xmlTextWriterEndElement(writer);
      if (status < 0) {
        [NSException raise: @"XMLWriteError"
                     format: @"Error writing end child element {}userKey."];
      }
    } //end item iterator.
  }
}
@end /* implementation DRIP_COMMONSNS0ConfUserKey (JAXB) */

#endif /* DEF_DRIP_COMMONSNS0ConfUserKey_M */
#ifndef DEF_DRIP_COMMONSNS0ConfScript_M
#define DEF_DRIP_COMMONSNS0ConfScript_M

/**
 * 
 *  @author S. Koulouzis
 */
@implementation DRIP_COMMONSNS0ConfScript

/**
 * The script contents with new lines replace by '\n'
 */
- (NSString *) script
{
  return _script;
}

/**
 * The script contents with new lines replace by '\n'
 */
- (void) setScript: (NSString *) newScript
{
  [newScript retain];
  [_script release];
  _script = newScript;
}

- (void) dealloc
{
  [self setScript: nil];
  [super dealloc];
}

//documentation inherited.
+ (id<EnunciateXML>) readFromXML: (NSData *) xml
{
  DRIP_COMMONSNS0ConfScript *_dRIP_COMMONSNS0ConfScript;
  xmlTextReaderPtr reader = xmlReaderForMemory([xml bytes], [xml length], NULL, NULL, 0);
  if (reader == NULL) {
    [NSException raise: @"XMLReadError"
                 format: @"Error instantiating an XML reader."];
    return nil;
  }

  _dRIP_COMMONSNS0ConfScript = (DRIP_COMMONSNS0ConfScript *) [DRIP_COMMONSNS0ConfScript readXMLElement: reader];
  xmlFreeTextReader(reader); //free the reader
  return _dRIP_COMMONSNS0ConfScript;
}

//documentation inherited.
- (NSData *) writeToXML
{
  xmlBufferPtr buf;
  xmlTextWriterPtr writer;
  int rc;
  NSData *data;

  buf = xmlBufferCreate();
  if (buf == NULL) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error creating an XML buffer."];
    return nil;
  }

  writer = xmlNewTextWriterMemory(buf, 0);
  if (writer == NULL) {
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error creating an XML writer."];
    return nil;
  }

  rc = xmlTextWriterStartDocument(writer, NULL, "utf-8", NULL);
  if (rc < 0) {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing XML start document."];
    return nil;
  }

  NS_DURING
  {
    [self writeXMLElement: writer];
  }
  NS_HANDLER
  {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [localException raise];
  }
  NS_ENDHANDLER

  rc = xmlTextWriterEndDocument(writer);
  if (rc < 0) {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing XML end document."];
    return nil;
  }

  xmlFreeTextWriter(writer);
  data = [NSData dataWithBytes: buf->content length: buf->use];
  xmlBufferFree(buf);
  return data;
}
@end /* implementation DRIP_COMMONSNS0ConfScript */

/**
 * Internal, private interface for JAXB reading and writing.
 */
@interface DRIP_COMMONSNS0ConfScript (JAXB) <JAXBReading, JAXBWriting, JAXBType, JAXBElement>

@end /*interface DRIP_COMMONSNS0ConfScript (JAXB)*/

/**
 * Internal, private implementation for JAXB reading and writing.
 */
@implementation DRIP_COMMONSNS0ConfScript (JAXB)

/**
 * Read an instance of DRIP_COMMONSNS0ConfScript from an XML reader.
 *
 * @param reader The reader.
 * @return An instance of DRIP_COMMONSNS0ConfScript defined by the XML reader.
 */
+ (id<JAXBType>) readXMLType: (xmlTextReaderPtr) reader
{
  DRIP_COMMONSNS0ConfScript *_dRIP_COMMONSNS0ConfScript = [[DRIP_COMMONSNS0ConfScript alloc] init];
  NS_DURING
  {
    [_dRIP_COMMONSNS0ConfScript initWithReader: reader];
  }
  NS_HANDLER
  {
    _dRIP_COMMONSNS0ConfScript = nil;
    [localException raise];
  }
  NS_ENDHANDLER

  [_dRIP_COMMONSNS0ConfScript autorelease];
  return _dRIP_COMMONSNS0ConfScript;
}

/**
 * Initialize this instance of DRIP_COMMONSNS0ConfScript according to
 * the XML being read from the reader.
 *
 * @param reader The reader.
 */
- (id) initWithReader: (xmlTextReaderPtr) reader
{
  return [super initWithReader: reader];
}

/**
 * Write the XML for this instance of DRIP_COMMONSNS0ConfScript to the writer.
 * Note that since we're only writing the XML type,
 * No start/end element will be written.
 *
 * @param reader The reader.
 */
- (void) writeXMLType: (xmlTextWriterPtr) writer
{
  [super writeXMLType:writer];
}

/**
 * Reads a DRIP_COMMONSNS0ConfScript from an XML reader. The element to be read is
 * "confScript".
 *
 * @param reader The XML reader.
 * @return The DRIP_COMMONSNS0ConfScript.
 */
+ (id<JAXBElement>) readXMLElement: (xmlTextReaderPtr) reader {
  int status;
  DRIP_COMMONSNS0ConfScript *_confScript = nil;

  if (xmlTextReaderNodeType(reader) != XML_READER_TYPE_ELEMENT) {
    status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
    if (status < 1) {
      [NSException raise: @"XMLReadError"
                   format: @"Error advancing the reader to start element confScript."];
    }
  }

  if (xmlStrcmp(BAD_CAST "confScript", xmlTextReaderConstLocalName(reader)) == 0
      && xmlTextReaderConstNamespaceUri(reader) == NULL) {
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read root element {}confScript.");
#endif
    _confScript = (DRIP_COMMONSNS0ConfScript *)[DRIP_COMMONSNS0ConfScript readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Successfully read root element {}confScript.");
#endif
  }
  else {
    if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
      [NSException raise: @"XMLReadError"
                   format: @"Unable to read DRIP_COMMONSNS0ConfScript. Expected element confScript. Current element: {}%s", xmlTextReaderConstLocalName(reader)];
    }
    else {
      [NSException raise: @"XMLReadError"
                   format: @"Unable to read DRIP_COMMONSNS0ConfScript. Expected element confScript. Current element: {%s}%s\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader)];
    }
  }

  return _confScript;
}

/**
 * Writes this DRIP_COMMONSNS0ConfScript to XML under element name "confScript".
 * The namespace declarations for the element will be written.
 *
 * @param writer The XML writer.
 * @param _confScript The ConfScript to write.
 * @return 1 if successful, 0 otherwise.
 */
- (void) writeXMLElement: (xmlTextWriterPtr) writer
{
  [self writeXMLElement: writer writeNamespaces: YES];
}

/**
 * Writes this DRIP_COMMONSNS0ConfScript to an XML writer.
 *
 * @param writer The writer.
 * @param writeNs Whether to write the namespaces for this element to the xml writer.
 */
- (void) writeXMLElement: (xmlTextWriterPtr) writer writeNamespaces: (BOOL) writeNs
{
  int rc = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "confScript", NULL);
  if (rc < 0) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing start element {}confScript. XML writer status: %i\n", rc];
  }

#if DEBUG_ENUNCIATE > 1
  NSLog(@"writing type {}confScript for root element {}confScript...");
#endif
  [self writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
  NSLog(@"successfully wrote type {}confScript for root element {}confScript...");
#endif
  rc = xmlTextWriterEndElement(writer);
  if (rc < 0) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing end element {}confScript. XML writer status: %i\n", rc];
  }
}

//documentation inherited.
- (BOOL) readJAXBAttribute: (xmlTextReaderPtr) reader
{
  void *_child_accessor;

  if ([super readJAXBAttribute: reader]) {
    return YES;
  }

  return NO;
}

//documentation inherited.
- (BOOL) readJAXBValue: (xmlTextReaderPtr) reader
{
  return [super readJAXBValue: reader];
}

//documentation inherited.
- (BOOL) readJAXBChildElement: (xmlTextReaderPtr) reader
{
  id __child;
  void *_child_accessor;
  int status, depth;

  if ([super readJAXBChildElement: reader]) {
    return YES;
  }
  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "script", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}script of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}script of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setScript: __child];
    return YES;
  } //end "if choice"


  return NO;
}

//documentation inherited.
- (int) readUnknownJAXBChildElement: (xmlTextReaderPtr) reader
{
  return [super readUnknownJAXBChildElement: reader];
}

//documentation inherited.
- (void) readUnknownJAXBAttribute: (xmlTextReaderPtr) reader
{
  [super readUnknownJAXBAttribute: reader];
}

//documentation inherited.
- (void) writeJAXBAttributes: (xmlTextWriterPtr) writer
{
  int status;

  [super writeJAXBAttributes: writer];

}

//documentation inherited.
- (void) writeJAXBValue: (xmlTextWriterPtr) writer
{
  [super writeJAXBValue: writer];
}

/**
 * Method for writing the child elements.
 *
 * @param writer The writer.
 */
- (void) writeJAXBChildElements: (xmlTextWriterPtr) writer
{
  int status;
  id __item;
  id __item_copy;
  NSEnumerator *__enumerator;

  [super writeJAXBChildElements: writer];

  if ([self script]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "script", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}script."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}script...");
#endif
    [[self script] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}script...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}script."];
    }
  }
}
@end /* implementation DRIP_COMMONSNS0ConfScript (JAXB) */

#endif /* DEF_DRIP_COMMONSNS0ConfScript_M */
