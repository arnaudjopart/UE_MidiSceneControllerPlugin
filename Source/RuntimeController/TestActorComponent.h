// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TestActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RUNTIMECONTROLLER_API UTestActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTestActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	TArray<FKey> Keys;

public:	
	// Called every frame
	UFUNCTION()
	void OnInputReceived(FKey Key);
	UFUNCTION(BlueprintCallable)
	bool AddKey(FKey Key);
	UFUNCTION(BlueprintCallable)
	bool RemoveKey(FKey Key);
	UFUNCTION(BlueprintCallable)
	bool HasKey(FKey Key);
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(EditAnywhere, Category = "Controller")
	FColor HighlightColor;
};
