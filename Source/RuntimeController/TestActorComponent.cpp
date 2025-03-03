// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActorComponent.h"

#include "InputListenerBasePawn.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTestActorComponent::UTestActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}



void UTestActorComponent::OnInputReceived(FKey Key)
{
	//UE_LOG(LogTemp, Display, TEXT("OnInputReceived - %s"),*Key.GetFName().ToString());
	if (HasKey(Key)) UE_LOG(LogTemp, Display, TEXT("%s Is Reacting"),*GetOwner()->GetActorNameOrLabel());
}

bool UTestActorComponent::AddKey(const FKey Key)
{
	if (Keys.Contains(Key))
	{
		return true;
	}
	Keys.Add(Key);

	return Keys.Contains(Key);
}

bool UTestActorComponent::RemoveKey(const FKey Key)
{
	if (Keys.Contains(Key))
	{
		Keys.Remove(Key);
	}
	
	return Keys.Contains(Key);
}

bool UTestActorComponent::HasKey(const FKey Key)
{
	return Keys.Contains(Key);
}


// Called when the game starts
void UTestActorComponent::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> Result;
	UGameplayStatics::GetAllActorsOfClass(this,AInputListenerBasePawn::StaticClass(),Result);
	if (Result.Num() > 0)
	{
		if (AInputListenerBasePawn* Listener = Cast<AInputListenerBasePawn>(Result[0]); Listener!=nullptr)
		{
			UE_LOG(LogTemp,Display,TEXT("TestActorComponent::BeginPlay - %s"),*Listener->GetActorNameOrLabel());
			Listener->OnInputReceivedEvent.AddDynamic(this, &UTestActorComponent::OnInputReceived);
		}
	}
}


// Called every frame
void UTestActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

