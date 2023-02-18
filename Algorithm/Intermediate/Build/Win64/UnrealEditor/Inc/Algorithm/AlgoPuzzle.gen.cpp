// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Algorithm/Public/AlgoPuzzle.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAlgoPuzzle() {}
// Cross Module References
	ALGORITHM_API UClass* Z_Construct_UClass_UAlgoPuzzle_NoRegister();
	ALGORITHM_API UClass* Z_Construct_UClass_UAlgoPuzzle();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_Algorithm();
// End Cross Module References
	void UAlgoPuzzle::StaticRegisterNativesUAlgoPuzzle()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAlgoPuzzle);
	UClass* Z_Construct_UClass_UAlgoPuzzle_NoRegister()
	{
		return UAlgoPuzzle::StaticClass();
	}
	struct Z_Construct_UClass_UAlgoPuzzle_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_cardValues_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_cardValues_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_cardValues;
		static const UECodeGen_Private::FIntPropertyParams NewProp_sameCards_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_sameCards_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_sameCards;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAlgoPuzzle_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_Algorithm,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAlgoPuzzle_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "AlgoPuzzle.h" },
		{ "ModuleRelativePath", "Public/AlgoPuzzle.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UAlgoPuzzle_Statics::NewProp_cardValues_Inner = { "cardValues", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAlgoPuzzle_Statics::NewProp_cardValues_MetaData[] = {
		{ "Comment", "// \xc4\xab?? ??(0, 1) ?\xe8\xbf\xad\n" },
		{ "ModuleRelativePath", "Public/AlgoPuzzle.h" },
		{ "ToolTip", "\xc4\xab?? ??(0, 1) ?\xe8\xbf\xad" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UAlgoPuzzle_Statics::NewProp_cardValues = { "cardValues", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UAlgoPuzzle, cardValues), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UAlgoPuzzle_Statics::NewProp_cardValues_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UAlgoPuzzle_Statics::NewProp_cardValues_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UAlgoPuzzle_Statics::NewProp_sameCards_Inner = { "sameCards", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAlgoPuzzle_Statics::NewProp_sameCards_MetaData[] = {
		{ "Comment", "// ???? \xc4\xab?? ???? ?????? ?\xe8\xbf\xad\n" },
		{ "ModuleRelativePath", "Public/AlgoPuzzle.h" },
		{ "ToolTip", "???? \xc4\xab?? ???? ?????? ?\xe8\xbf\xad" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UAlgoPuzzle_Statics::NewProp_sameCards = { "sameCards", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UAlgoPuzzle, sameCards), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UAlgoPuzzle_Statics::NewProp_sameCards_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UAlgoPuzzle_Statics::NewProp_sameCards_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAlgoPuzzle_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAlgoPuzzle_Statics::NewProp_cardValues_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAlgoPuzzle_Statics::NewProp_cardValues,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAlgoPuzzle_Statics::NewProp_sameCards_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAlgoPuzzle_Statics::NewProp_sameCards,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAlgoPuzzle_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAlgoPuzzle>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UAlgoPuzzle_Statics::ClassParams = {
		&UAlgoPuzzle::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UAlgoPuzzle_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UAlgoPuzzle_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UAlgoPuzzle_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UAlgoPuzzle_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAlgoPuzzle()
	{
		if (!Z_Registration_Info_UClass_UAlgoPuzzle.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAlgoPuzzle.OuterSingleton, Z_Construct_UClass_UAlgoPuzzle_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UAlgoPuzzle.OuterSingleton;
	}
	template<> ALGORITHM_API UClass* StaticClass<UAlgoPuzzle>()
	{
		return UAlgoPuzzle::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAlgoPuzzle);
	struct Z_CompiledInDeferFile_FID_Algorithm_Source_Algorithm_Public_AlgoPuzzle_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Algorithm_Source_Algorithm_Public_AlgoPuzzle_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UAlgoPuzzle, UAlgoPuzzle::StaticClass, TEXT("UAlgoPuzzle"), &Z_Registration_Info_UClass_UAlgoPuzzle, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAlgoPuzzle), 3342279166U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Algorithm_Source_Algorithm_Public_AlgoPuzzle_h_2064244885(TEXT("/Script/Algorithm"),
		Z_CompiledInDeferFile_FID_Algorithm_Source_Algorithm_Public_AlgoPuzzle_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Algorithm_Source_Algorithm_Public_AlgoPuzzle_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
