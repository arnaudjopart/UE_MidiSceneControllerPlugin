// Fill out your copyright notice in the Description page of Project Settings.


#include "InputListenerBasePawn.h"




// Sets default values
AInputListenerBasePawn::AInputListenerBasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AInputListenerBasePawn::TestEvent(FKey InputId)
{
	UE_LOG(LogTemp, Display, TEXT("TestEvent - %s"),*InputId.ToString());
}

// Called when the game starts or when spawned
void AInputListenerBasePawn::BeginPlay()
{
	Super::BeginPlay();
	//OnInputReceivedEvent.AddUniqueDynamic(this,&AInputListenerBasePawn::TestEvent);
}

// Called every frame
void AInputListenerBasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AInputListenerBasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AInputListenerBasePawn::ProcessInput(FKey Key)
{
	//UE_LOG(LogTemp, Display, TEXT("AInputListenerBasePawn::ProcessInput - %s"),*Key.GetDisplayName().ToString());
	OnInputReceivedEvent.Broadcast(Key);
	
}

