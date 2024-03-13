// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "HexWorld.generated.h"

UCLASS()
class MINCECRAP3_API AHexWorld : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHexWorld();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void CreateHex();
	UPROPERTY(EditAnywhere)
	int  size;
	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* ProceduralMesh;
	UPROPERTY(EditAnywhere)
	TArray<UMaterial*>  MATS;
	//UPROPERTY(VisibleAnywhere)
	TArray<FVector> Vertices;
	//UPROPERTY(VisibleAnywhere)
	TArray<int32> Triangles;
};
