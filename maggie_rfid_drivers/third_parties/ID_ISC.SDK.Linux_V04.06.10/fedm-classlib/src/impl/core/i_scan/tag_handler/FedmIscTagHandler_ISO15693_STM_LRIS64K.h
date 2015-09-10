/*-------------------------------------------------------
|                                                       |
|	   FedmIscTagHandler_ISO15693_STM_LRIS64K.h			|
|                                                       |
---------------------------------------------------------

Copyright � 2009-2012	FEIG ELECTRONIC GmbH, All Rights Reserved.
						Lange Strasse 4
						D-35781 Weilburg
						Federal Republic of Germany
						phone    : +49 6471 31090
						fax      : +49 6471 310999
						e-mail   : obid-support@feig.de
						Internet : http://www.feig.de
					
Author         		:	Markus Hultsch
Begin        		:	25.09.2012

Version       		:	04.03.01 / 10.02.2010 / M. Hultsch

Operation Systems	:	independent

Function			:	class for OBID i-scan� HF transponder ISO15693 of manufacturer STMicroelectronics SA
						specialized tag handler on top with custom specific commands

NOTE				:	this class supports only selected or addressed mode in Host-Mode


Trademarks:
-----------
OBID�, OBID i-scan� and OBID myAXXESS� are registered Trademarks of FEIG ELECTRONIC GmbH
Other Trademarks: see FEDM.h
*/

#if !defined(_FEDM_ISC_TAG_HANDLER_ISO15693_STM_LRIS64K_H_INCLUDED_)
#define _FEDM_ISC_TAG_HANDLER_ISO15693_STM_LRIS64K_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#include "../../FEDM.h"
#include "FedmIscTagHandler_ISO15693_STM_M24LR64R.h"

class FEDM_ISOTabItem;



//#####################################################################################
// constants
//#####################################################################################





//####################################################################
// class FedmIscTagHandler_ISO15693_STM_LRIS64K
// >> supports only ISO Host Commands <<
//####################################################################

/// @brief Transponder class providing manufacturer specific commands for ISO 15693 compliant Transponders of type LRIS64K from manufacturer STMicroelectronics SA
///
/// <b>Description</b><br>
/// High-level class for easy-to-use Transponder specific communication. See OBID::FEDM::Core::ITagGroup for additional information.<br>
/// All methods are similiar to specific commands of LRIS64K. Thus, you must refer to the Technical Datasheet of the LRIS64K to get detailed information about the methods and the parameters.<br>
/// Secondly, all methods of this class are Custom specific commands, realized with the Reader command [0xB1], which are described in the Application Note <i>STMicroelectronics Custom and Proprietary Commands.pdf</i>
///
/// @note Programmers should be familiar with the ISO 15693 standard
class _FEDM_ISC_CORE_EXT_CLASS FedmIscTagHandler_ISO15693_STM_LRIS64K : public FedmIscTagHandler_ISO15693_STM_M24LR64R
{
public:

	// friend classes have access rights to protected members
	friend class FEDM_ISCReaderModule;
	friend class FEDM_ISCReader;
	friend class FEDM_ISOTabItem;

protected:
	// constructor
	FedmIscTagHandler_ISO15693_STM_LRIS64K(FEDM_ISCReader* pReader, FEDM_ISOTabItem* pTabItem);
	// 2. constructor
	FedmIscTagHandler_ISO15693_STM_LRIS64K(FEDM_ISCReader* pReader, unsigned int uiTagHandlerType, FEDM_ISOTabItem* pTabItem);
	// destructor
	virtual ~FedmIscTagHandler_ISO15693_STM_LRIS64K();

};

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#endif // !defined(_FEDM_ISC_TAG_HANDLER_ISO15693_STM_LRIS64K_H_INCLUDED_)
