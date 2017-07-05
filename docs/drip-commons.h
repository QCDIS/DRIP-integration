#import "enunciate-common.h"

@class DRIP_COMMONSNS0Execute;
@class DRIP_COMMONSNS0Configure;
@class DRIP_COMMONSNS0LoginKey0;
@class DRIP_COMMONSNS0Register;
@class DRIP_COMMONSNS0Upload;
@class DRIP_COMMONSNS0Result;
@class DRIP_COMMONSNS0Plan;
@class DRIP_COMMONSNS0Attribute;
@class DRIP_COMMONSNS0Deploy;
@class DRIP_COMMONSNS0ConfUserKey;
@class DRIP_COMMONSNS0ConfScript;

#ifndef DEF_DRIP_COMMONSNS0Execute_H
#define DEF_DRIP_COMMONSNS0Execute_H

/**
 * 
 *  @author S. Koulouzis
 */
@interface DRIP_COMMONSNS0Execute : NSObject <EnunciateXML>
{
  @private
    NSString *_user;
    NSString *_pwd;
    NSString *_action;
}

/**
 * Not used. It's there for backwards compatibility.
 */
- (NSString *) user;

/**
 * Not used. It's there for backwards compatibility.
 */
- (void) setUser: (NSString *) newUser;

/**
 * Not used. It's there for backwards compatibility.
 */
- (NSString *) pwd;

/**
 * Not used. It's there for backwards compatibility.
 */
- (void) setPwd: (NSString *) newPwd;

/**
 * A referance id used from the servcie to do the provisioning
 */
- (NSString *) action;

/**
 * A referance id used from the servcie to do the provisioning
 */
- (void) setAction: (NSString *) newAction;
@end /* interface DRIP_COMMONSNS0Execute */

#endif /* DEF_DRIP_COMMONSNS0Execute_H */
#ifndef DEF_DRIP_COMMONSNS0Configure_H
#define DEF_DRIP_COMMONSNS0Configure_H

/**
 * 
 *  @author S. Koulouzis
 */
@interface DRIP_COMMONSNS0Configure : NSObject <EnunciateXML>
{
  @private
    NSString *_user;
    NSString *_pwd;
    NSString *_keyid;
    NSString *_key;
    NSArray *_loginKey;
    NSString *_geniKey;
    NSString *_geniKeyAlias;
    NSArray *_loginPubKey;
    NSString *_geniKeyPass;
    NSArray *_loginPriKey;
}

/**
 * Not used. It's there for backwards compatibility.
 */
- (NSString *) user;

/**
 * Not used. It's there for backwards compatibility.
 */
- (void) setUser: (NSString *) newUser;

/**
 * Not used. It's there for backwards compatibility.
 */
- (NSString *) pwd;

/**
 * Not used. It's there for backwards compatibility.
 */
- (void) setPwd: (NSString *) newPwd;

/**
 * The key id for the cloud provider.
 */
- (NSString *) keyid;

/**
 * The key id for the cloud provider.
 */
- (void) setKeyid: (NSString *) newKeyid;

/**
 * The key for the cloud provider.
 */
- (NSString *) key;

/**
 * The key for the cloud provider.
 */
- (void) setKey: (NSString *) newKey;

/**
 * (no documentation provided)
 */
- (NSArray *) loginKey;

/**
 * (no documentation provided)
 */
- (void) setLoginKey: (NSArray *) newLoginKey;

/**
 * The binary keystore (user.jks) for the cloud provider encoded in base64
 */
- (NSString *) geniKey;

/**
 * The binary keystore (user.jks) for the cloud provider encoded in base64
 */
- (void) setGeniKey: (NSString *) newGeniKey;

/**
 * Key alias in key store
 */
- (NSString *) geniKeyAlias;

/**
 * Key alias in key store
 */
- (void) setGeniKeyAlias: (NSString *) newGeniKeyAlias;

/**
 * (no documentation provided)
 */
- (NSArray *) loginPubKey;

/**
 * (no documentation provided)
 */
- (void) setLoginPubKey: (NSArray *) newLoginPubKey;

/**
 * (no documentation provided)
 */
- (NSString *) geniKeyPass;

/**
 * (no documentation provided)
 */
- (void) setGeniKeyPass: (NSString *) newGeniKeyPass;

/**
 * (no documentation provided)
 */
- (NSArray *) loginPriKey;

/**
 * (no documentation provided)
 */
- (void) setLoginPriKey: (NSArray *) newLoginPriKey;
@end /* interface DRIP_COMMONSNS0Configure */

#endif /* DEF_DRIP_COMMONSNS0Configure_H */
#ifndef DEF_DRIP_COMMONSNS0LoginKey0_H
#define DEF_DRIP_COMMONSNS0LoginKey0_H

/**
 * 
 *  @author S. Koulouzis
 */
@interface DRIP_COMMONSNS0LoginKey0 : NSObject
{
  @private
    NSString *_domain_name;
    NSString *_content;
}

/**
 * (no documentation provided)
 */
- (NSString *) domain_name;

/**
 * (no documentation provided)
 */
- (void) setDomain_name: (NSString *) newDomain_name;

/**
 * (no documentation provided)
 */
- (NSString *) content;

/**
 * (no documentation provided)
 */
- (void) setContent: (NSString *) newContent;
@end /* interface DRIP_COMMONSNS0LoginKey0 */

#endif /* DEF_DRIP_COMMONSNS0LoginKey0_H */
#ifndef DEF_DRIP_COMMONSNS0Register_H
#define DEF_DRIP_COMMONSNS0Register_H

/**
 * 
 *  @author S. Koulouzis
 */
@interface DRIP_COMMONSNS0Register : NSObject <EnunciateXML>
{
  @private
    NSString *_user;
    NSString *_pwd;
}

/**
 * The user name
 */
- (NSString *) user;

/**
 * The user name
 */
- (void) setUser: (NSString *) newUser;

/**
 * The user password
 */
- (NSString *) pwd;

/**
 * The user password
 */
- (void) setPwd: (NSString *) newPwd;
@end /* interface DRIP_COMMONSNS0Register */

#endif /* DEF_DRIP_COMMONSNS0Register_H */
#ifndef DEF_DRIP_COMMONSNS0Upload_H
#define DEF_DRIP_COMMONSNS0Upload_H

/**
 * 
 *  @author S. Koulouzis
 */
@interface DRIP_COMMONSNS0Upload : NSObject <EnunciateXML>
{
  @private
    NSString *_user;
    NSString *_pwd;
    NSArray *_file;
}

/**
 * (no documentation provided)
 */
- (NSString *) user;

/**
 * (no documentation provided)
 */
- (void) setUser: (NSString *) newUser;

/**
 * (no documentation provided)
 */
- (NSString *) pwd;

/**
 * (no documentation provided)
 */
- (void) setPwd: (NSString *) newPwd;

/**
 * (no documentation provided)
 */
- (NSArray *) file;

/**
 * (no documentation provided)
 */
- (void) setFile: (NSArray *) newFile;
@end /* interface DRIP_COMMONSNS0Upload */

#endif /* DEF_DRIP_COMMONSNS0Upload_H */
#ifndef DEF_DRIP_COMMONSNS0Result_H
#define DEF_DRIP_COMMONSNS0Result_H

/**
 * 
 *  @author S. Koulouzis
 */
@interface DRIP_COMMONSNS0Result : NSObject <EnunciateXML>
{
  @private
    NSString *_status;
    NSString *_info;
    NSArray *_file;
}

/**
 * The status of the response
 */
- (NSString *) status;

/**
 * The status of the response
 */
- (void) setStatus: (NSString *) newStatus;

/**
 * Not used. Not used. It's there for backwards compatibility.
 */
- (NSString *) info;

/**
 * Not used. Not used. It's there for backwards compatibility.
 */
- (void) setInfo: (NSString *) newInfo;

/**
 * (no documentation provided)
 */
- (NSArray *) file;

/**
 * (no documentation provided)
 */
- (void) setFile: (NSArray *) newFile;
@end /* interface DRIP_COMMONSNS0Result */

#endif /* DEF_DRIP_COMMONSNS0Result_H */
#ifndef DEF_DRIP_COMMONSNS0Plan_H
#define DEF_DRIP_COMMONSNS0Plan_H

/**
 * 
 *  This class represents a plan to be provided to the planner.
 * 
 *  @author S. Koulouzis
 */
@interface DRIP_COMMONSNS0Plan : NSObject <EnunciateXML>
{
  @private
    NSString *_user;
    NSString *_pwd;
    NSString *_file;
}

/**
 * Not used. It's only there for backwords compatibility
 */
- (NSString *) user;

/**
 * Not used. It's only there for backwords compatibility
 */
- (void) setUser: (NSString *) newUser;

/**
 * Not used. It's only there for backwords compatibility
 */
- (NSString *) pwd;

/**
 * Not used. It's only there for backwords compatibility
 */
- (void) setPwd: (NSString *) newPwd;

/**
 * The contents of the TOSCA description
 */
- (NSString *) file;

/**
 * The contents of the TOSCA description
 */
- (void) setFile: (NSString *) newFile;
@end /* interface DRIP_COMMONSNS0Plan */

#endif /* DEF_DRIP_COMMONSNS0Plan_H */
#ifndef DEF_DRIP_COMMONSNS0Attribute_H
#define DEF_DRIP_COMMONSNS0Attribute_H

/**
 * 
 *  @author S. Koulouzis
 */
@interface DRIP_COMMONSNS0Attribute : NSObject
{
  @private
    NSString *_name;
    NSString *_level;
    NSString *_content;
}

/**
 * Name of the file/public key.
 */
- (NSString *) name;

/**
 * Name of the file/public key.
 */
- (void) setName: (NSString *) newName;

/**
 * There are two levels of description files for topologies designed by users.
 * If the level attribute for the element file is 1, then this file is the top-level description,
 * which defines how the sub-topologies are connected to each other.
 * If the level attribute is 0, then the file is the low-level description,
 * which describes the topology in one data center in detail.
 * On the other hand, the name of low-level description file must be the
 * sub-topology name appeared in the high-level description file. (For example, here should be zh_a and zh_b.)
 */
- (NSString *) level;

/**
 * There are two levels of description files for topologies designed by users.
 * If the level attribute for the element file is 1, then this file is the top-level description,
 * which defines how the sub-topologies are connected to each other.
 * If the level attribute is 0, then the file is the low-level description,
 * which describes the topology in one data center in detail.
 * On the other hand, the name of low-level description file must be the
 * sub-topology name appeared in the high-level description file. (For example, here should be zh_a and zh_b.)
 */
- (void) setLevel: (NSString *) newLevel;

/**
 * (no documentation provided)
 */
- (NSString *) content;

/**
 * (no documentation provided)
 */
- (void) setContent: (NSString *) newContent;
@end /* interface DRIP_COMMONSNS0Attribute */

#endif /* DEF_DRIP_COMMONSNS0Attribute_H */
#ifndef DEF_DRIP_COMMONSNS0Deploy_H
#define DEF_DRIP_COMMONSNS0Deploy_H

/**
 * 
 *  @author S. Koulouzis
 */
@interface DRIP_COMMONSNS0Deploy : DRIP_COMMONSNS0Execute <EnunciateXML>
{
  @private
}
@end /* interface DRIP_COMMONSNS0Deploy */

#endif /* DEF_DRIP_COMMONSNS0Deploy_H */
#ifndef DEF_DRIP_COMMONSNS0ConfUserKey_H
#define DEF_DRIP_COMMONSNS0ConfUserKey_H

/**
 * 
 *  @author S. Koulouzis
 */
@interface DRIP_COMMONSNS0ConfUserKey : DRIP_COMMONSNS0Execute <EnunciateXML>
{
  @private
    NSArray *_file;
}

/**
 * (no documentation provided)
 */
- (NSArray *) file;

/**
 * (no documentation provided)
 */
- (void) setFile: (NSArray *) newFile;
@end /* interface DRIP_COMMONSNS0ConfUserKey */

#endif /* DEF_DRIP_COMMONSNS0ConfUserKey_H */
#ifndef DEF_DRIP_COMMONSNS0ConfScript_H
#define DEF_DRIP_COMMONSNS0ConfScript_H

/**
 * 
 *  @author S. Koulouzis
 */
@interface DRIP_COMMONSNS0ConfScript : DRIP_COMMONSNS0Execute <EnunciateXML>
{
  @private
    NSString *_script;
}

/**
 * The script contents with new lines replace by '\n'
 */
- (NSString *) script;

/**
 * The script contents with new lines replace by '\n'
 */
- (void) setScript: (NSString *) newScript;
@end /* interface DRIP_COMMONSNS0ConfScript */

#endif /* DEF_DRIP_COMMONSNS0ConfScript_H */
