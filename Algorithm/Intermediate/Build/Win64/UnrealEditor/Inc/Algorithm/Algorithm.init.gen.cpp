// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAlgorithm_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Algorithm;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Algorithm()
	{
		if (!Z_Registration_Info_UPackage__Script_Algorithm.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Algorithm",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x374EDFD5,
				0xCED4C743,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Algorithm.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Algorithm.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Algorithm(Z_Construct_UPackage__Script_Algorithm, TEXT("/Script/Algorithm"), Z_Registration_Info_UPackage__Script_Algorithm, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x374EDFD5, 0xCED4C743));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
