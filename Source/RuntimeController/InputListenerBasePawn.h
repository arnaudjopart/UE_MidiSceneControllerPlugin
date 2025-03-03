// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputListenerBasePawn.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInputReceivedSignature, FKey, InputId);

UCLASS()
class RUNTIMECONTROLLER_API AInputListenerBasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AInputListenerBasePawn();

protected:
	UFUNCTION()
	void TestEvent(FKey InputId);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void ProcessInput(FKey Key);

	UPROPERTY(BlueprintAssignable,BlueprintReadWrite)
	FOnInputReceivedSignature OnInputReceivedEvent;
};
