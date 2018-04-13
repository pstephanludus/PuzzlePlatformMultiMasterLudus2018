// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"


AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority()) /* Si mod�le client-serveur l'autorit� d'ex�cution du code suivant est donn�e au serveur
							Si pas de serveur, l'exec du code est donn�e � la premi�re instance game */
	{
		FVector Location = GetActorLocation();
		float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
		float JourneyTravelled = (Location - GlobalStartLocation).Size();

		if (JourneyTravelled >= JourneyLength)
		{
			/*Si d�placement >= widgetLocation
			Alors swap = position de d�part
			GlobalStartLocation devient GlobalTargetLocation
			GlobalTargetLocation devient swap*/

			FVector Swap = GlobalStartLocation;
			GlobalStartLocation = GlobalTargetLocation;
			GlobalTargetLocation = Swap;
		}

		FVector Direction = (GlobalTargetLocation - Location).GetSafeNormal();
		Location += Speed * DeltaTime * Direction;
		SetActorLocation(Location);

		/*
		if (GetActorLocation() == Target)
		{
			if (Target == FirstTarget)
			{
				Target = Origin;
			}
			else
			{
				Target = FirstTarget;
			}
		}
		*/
	}
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		this->SetReplicates(true);
		this->SetReplicateMovement(true);		// s'applique � l'actor lui-m�me
	}

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}
