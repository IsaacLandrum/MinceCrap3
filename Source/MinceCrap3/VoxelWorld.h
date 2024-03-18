// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "VoxelWorld.generated.h"

UCLASS()
class MINCECRAP3_API AVoxelWorld : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVoxelWorld();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void CreateVoxel();
	UFUNCTION(CallInEditor, BlueprintCallable, Category = "Voxel")
	void EraseVoxel(int x, int y);
	void Refresh();
	UPROPERTY(EditAnywhere)
	int  size;
	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* ProceduralMesh;
	UPROPERTY(EditAnywhere)
	TArray<UMaterial*> MATS;
	TArray<FVector> Vertices;
	//UPROPERTY(VisibleAnywhere)
	TArray<int32> Triangles;
};
