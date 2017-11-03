// Copyright WW Design & Consulting, Inc. 2017

#include "OpenDoor.h"
#include "Engine/World.h"
#include "Gameframework/Actor.h"
#include "Gameframework/PlayerController.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the trigger volume every frame
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		//	If the ActorThatOpens is in the volume
		OpenDoor();
	}

	

}

void UOpenDoor::OpenDoor()
{
	AActor* Owner = GetOwner();

	FRotator NewRotation = FRotator(0.0f, -60.0f, 0.0f);
	Owner->SetActorRotation(NewRotation);
}
