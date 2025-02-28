// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "ActorExplorerUtilityWidget.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class ACTOREXPLORER_API UActorExplorerUtilityWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "ActorExplorer")
	void ListActorFunctions(AActor* Actor);
	UFUNCTION(BlueprintCallable, Category = "ActorExplorer")
	void SayHello();
};
