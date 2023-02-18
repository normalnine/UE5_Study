// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Algorithm/Public/Cube.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCube() {}
// Cross Module References
	ALGORITHM_API UClass* Z_Construct_UClass_ACube_NoRegister();
	ALGORITHM_API UClass* Z_Construct_UClass_ACube();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Algorithm();
	UMG_API UClass* Z_Construct_UClass_UBorder_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
// End Cross Module References
	void ACube::StaticRegisterNativesACube()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACube);
	UClass* Z_Construct_UClass_ACube_NoRegister()
	{
		return ACube::StaticClass();
	}
	struct Z_Construct_UClass_ACube_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_outLine_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_outLine;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_textTotal_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_textTotal;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_textStart_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_textStart;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_textGoal_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_textGoal;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_parentCube_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_parentCube;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACube_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Algorithm,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACube_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Cube.h" },
		{ "ModuleRelativePath", "Public/Cube.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACube_Statics::NewProp_outLine_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Cube.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACube_Statics::NewProp_outLine = { "outLine", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACube, outLine), Z_Construct_UClass_UBorder_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACube_Statics::NewProp_outLine_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACube_Statics::NewProp_outLine_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACube_Statics::NewProp_textTotal_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Cube.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACube_Statics::NewProp_textTotal = { "textTotal", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACube, textTotal), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACube_Statics::NewProp_textTotal_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACube_Statics::NewProp_textTotal_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACube_Statics::NewProp_textStart_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Cube.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACube_Statics::NewProp_textStart = { "textStart", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACube, textStart), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACube_Statics::NewProp_textStart_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACube_Statics::NewProp_textStart_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACube_Statics::NewProp_textGoal_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Cube.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACube_Statics::NewProp_textGoal = { "textGoal", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACube, textGoal), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACube_Statics::NewProp_textGoal_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACube_Statics::NewProp_textGoal_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACube_Statics::NewProp_parentCube_MetaData[] = {
		{ "ModuleRelativePath", "Public/Cube.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACube_Statics::NewProp_parentCube = { "parentCube", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACube, parentCube), Z_Construct_UClass_ACube_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACube_Statics::NewProp_parentCube_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACube_Statics::NewProp_parentCube_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACube_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACube_Statics::NewProp_outLine,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACube_Statics::NewProp_textTotal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACube_Statics::NewProp_textStart,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACube_Statics::NewProp_textGoal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACube_Statics::NewProp_parentCube,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACube_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACube>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ACube_Statics::ClassParams = {
		&ACube::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ACube_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ACube_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACube_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACube_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACube()
	{
		if (!Z_Registration_Info_UClass_ACube.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACube.OuterSingleton, Z_Construct_UClass_ACube_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ACube.OuterSingleton;
	}
	template<> ALGORITHM_API UClass* StaticClass<ACube>()
	{
		return ACube::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACube);
	struct Z_CompiledInDeferFile_FID_Algorithm_Source_Algorithm_Public_Cube_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Algorithm_Source_Algorithm_Public_Cube_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ACube, ACube::StaticClass, TEXT("ACube"), &Z_Registration_Info_UClass_ACube, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACube), 2810765006U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Algorithm_Source_Algorithm_Public_Cube_h_2927741665(TEXT("/Script/Algorithm"),
		Z_CompiledInDeferFile_FID_Algorithm_Source_Algorithm_Public_Cube_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Algorithm_Source_Algorithm_Public_Cube_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
