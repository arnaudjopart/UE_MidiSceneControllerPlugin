// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GlobalDataAsset.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class RUNTIMECONTROLLER_API UGlobalDataAsset : public UDataAsset
{
	GENERATED_BODY()

	public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DataAssetPath;
};
