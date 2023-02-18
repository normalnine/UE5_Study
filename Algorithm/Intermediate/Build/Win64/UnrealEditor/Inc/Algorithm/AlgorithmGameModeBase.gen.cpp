// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Algorithm/AlgorithmGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAlgorithmGameModeBase() {}
// Cross Module References
	ALGORITHM_API UClass* Z_Construct_UClass_AAlgorithmGameModeBase_NoRegister();
	ALGORITHM_API UClass* Z_Construct_UClass_AAlgorithmGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Algorithm();
// End Cross Module References
	void AAlgorithmGameModeBase::StaticRegisterNativesAAlgorithmGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAlgorithmGameModeBase);
	UClass* Z_Construct_UClass_AAlgorithmGameModeBase_NoRegister()
	{
		return AAlgorithmGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AAlgorithmGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAlgorithmGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Algorithm,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlgorithmGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "AlgorithmGameModeBase.h" },
		{ "ModuleRelativePath", "AlgorithmGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAlgorithmGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAlgorithmGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AAlgorithmGameModeBase_Statics::ClassParams = {
		&AAlgorithmGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AAlgorithmGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAlgorithmGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAlgorithmGameModeBase()
	{
		if (!Z_Registration_Info_UClass_AAlgorithmGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAlgorithmGameModeBase.OuterSingleton, Z_Construct_UClass_AAlgorithmGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AAlgorithmGameModeBase.OuterSingleton;
	}
	template<> ALGORITHM_API UClass* StaticClass<AAlgorithmGameModeBase>()
	{
		return AAlgorithmGameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAlgorithmGameModeBase);
	struct Z_CompiledInDeferFile_FID_Algorithm_Source_Algorithm_AlgorithmGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Algorithm_Source_Algorithm_AlgorithmGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AAlgorithmGameModeBase, AAlgorithmGameModeBase::StaticClass, TEXT("AAlgorithmGameModeBase"), &Z_Registration_Info_UClass_AAlgorithmGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAlgorithmGameModeBase), 4207918308U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Algorithm_Source_Algorithm_AlgorithmGameModeBase_h_3379032196(TEXT("/Script/Algorithm"),
		Z_CompiledInDeferFile_FID_Algorithm_Source_Algorithm_AlgorithmGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Algorithm_Source_Algorithm_AlgorithmGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
