// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Algorithm/Public/AlgoPlayer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAlgoPlayer() {}
// Cross Module References
	ALGORITHM_API UClass* Z_Construct_UClass_AAlgoPlayer_NoRegister();
	ALGORITHM_API UClass* Z_Construct_UClass_AAlgoPlayer();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_Algorithm();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ALGORITHM_API UClass* Z_Construct_UClass_UAlgoPuzzle_NoRegister();
	ALGORITHM_API UClass* Z_Construct_UClass_ACube_NoRegister();
// End Cross Module References
	void AAlgoPlayer::StaticRegisterNativesAAlgoPlayer()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAlgoPlayer);
	UClass* Z_Construct_UClass_AAlgoPlayer_NoRegister()
	{
		return AAlgoPlayer::StaticClass();
	}
	struct Z_Construct_UClass_AAlgoPlayer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_puzzleFactory_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_puzzleFactory;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_puzzle_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_puzzle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_startCube_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_startCube;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_goalCube_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_goalCube;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_currCube_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_currCube;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_openArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_openArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_openArray;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_closeArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_closeArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_closeArray;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_pathArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_pathArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_pathArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAlgoPlayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_Algorithm,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlgoPlayer_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "AlgoPlayer.h" },
		{ "ModuleRelativePath", "Public/AlgoPlayer.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_puzzleFactory_MetaData[] = {
		{ "Category", "AlgoPlayer" },
		{ "ModuleRelativePath", "Public/AlgoPlayer.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_puzzleFactory = { "puzzleFactory", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAlgoPlayer, puzzleFactory), Z_Construct_UClass_UAlgoPuzzle_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_puzzleFactory_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_puzzleFactory_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_puzzle_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/AlgoPlayer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_puzzle = { "puzzle", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAlgoPlayer, puzzle), Z_Construct_UClass_UAlgoPuzzle_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_puzzle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_puzzle_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_startCube_MetaData[] = {
		{ "Category", "AlgoPlayer" },
		{ "ModuleRelativePath", "Public/AlgoPlayer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_startCube = { "startCube", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAlgoPlayer, startCube), Z_Construct_UClass_ACube_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_startCube_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_startCube_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_goalCube_MetaData[] = {
		{ "Category", "AlgoPlayer" },
		{ "ModuleRelativePath", "Public/AlgoPlayer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_goalCube = { "goalCube", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAlgoPlayer, goalCube), Z_Construct_UClass_ACube_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_goalCube_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_goalCube_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_currCube_MetaData[] = {
		{ "Category", "AlgoPlayer" },
		{ "ModuleRelativePath", "Public/AlgoPlayer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_currCube = { "currCube", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAlgoPlayer, currCube), Z_Construct_UClass_ACube_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_currCube_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_currCube_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_openArray_Inner = { "openArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_ACube_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_openArray_MetaData[] = {
		{ "ModuleRelativePath", "Public/AlgoPlayer.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_openArray = { "openArray", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAlgoPlayer, openArray), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_openArray_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_openArray_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_closeArray_Inner = { "closeArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_ACube_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_closeArray_MetaData[] = {
		{ "ModuleRelativePath", "Public/AlgoPlayer.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_closeArray = { "closeArray", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAlgoPlayer, closeArray), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_closeArray_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_closeArray_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_pathArray_Inner = { "pathArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_ACube_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_pathArray_MetaData[] = {
		{ "ModuleRelativePath", "Public/AlgoPlayer.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_pathArray = { "pathArray", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAlgoPlayer, pathArray), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_pathArray_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_pathArray_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAlgoPlayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_puzzleFactory,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_puzzle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_startCube,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_goalCube,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_currCube,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_openArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_openArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_closeArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_closeArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_pathArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlgoPlayer_Statics::NewProp_pathArray,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAlgoPlayer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAlgoPlayer>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AAlgoPlayer_Statics::ClassParams = {
		&AAlgoPlayer::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AAlgoPlayer_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AAlgoPlayer_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AAlgoPlayer_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAlgoPlayer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAlgoPlayer()
	{
		if (!Z_Registration_Info_UClass_AAlgoPlayer.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAlgoPlayer.OuterSingleton, Z_Construct_UClass_AAlgoPlayer_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AAlgoPlayer.OuterSingleton;
	}
	template<> ALGORITHM_API UClass* StaticClass<AAlgoPlayer>()
	{
		return AAlgoPlayer::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAlgoPlayer);
	struct Z_CompiledInDeferFile_FID_Algorithm_Source_Algorithm_Public_AlgoPlayer_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Algorithm_Source_Algorithm_Public_AlgoPlayer_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AAlgoPlayer, AAlgoPlayer::StaticClass, TEXT("AAlgoPlayer"), &Z_Registration_Info_UClass_AAlgoPlayer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAlgoPlayer), 1085400043U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Algorithm_Source_Algorithm_Public_AlgoPlayer_h_1321284597(TEXT("/Script/Algorithm"),
		Z_CompiledInDeferFile_FID_Algorithm_Source_Algorithm_Public_AlgoPlayer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Algorithm_Source_Algorithm_Public_AlgoPlayer_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
