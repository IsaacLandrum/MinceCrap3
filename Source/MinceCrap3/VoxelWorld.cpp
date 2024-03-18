// Fill out your copyright notice in the Description page of Project Settings.

#include "Math/UnrealMathUtility.h"
#include "VoxelWorld.h"

// Sets default values
AVoxelWorld::AVoxelWorld()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ProceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = ProceduralMesh;
}
void AVoxelWorld::CreateVoxel() 
{
	double offset_x = 0;
	double offset_y = 0;
	double z = 0;
	int triangle_offset = 0;

	Vertices.Add(FVector(-100 + offset_x, 100 + offset_y, z + 100));
	Vertices.Add(FVector(100 + offset_x, 100 + offset_y, z + 100));
	Vertices.Add(FVector(100 + offset_x, -100 + offset_y, z + 100));
	Vertices.Add(FVector(-100 + offset_x, 100 + offset_y, z + 100));
	Vertices.Add(FVector(-100 + offset_x, -100 + offset_y, z + 100));
	Vertices.Add(FVector(100 + offset_x, -100 + offset_y, z + 100));
	
	Vertices.Add(FVector(-100 + offset_x, 100 + offset_y, z-100));
	Vertices.Add(FVector(100 + offset_x, 100 + offset_y, z-100));
	Vertices.Add(FVector(100 + offset_x, -100 + offset_y, z -100));
	Vertices.Add(FVector(-100 + offset_x, 100 + offset_y, z -100));
	Vertices.Add(FVector(-100 + offset_x, -100 + offset_y, z - 100));
	Vertices.Add(FVector(100 + offset_x, -100 + offset_y, z - 100));

	Vertices.Add(FVector(100 + offset_x, 100 + offset_y, z + 100));
	Vertices.Add(FVector(100 + offset_x, -100 + offset_y, z - 100));
	Vertices.Add(FVector(100 + offset_x, 100 + offset_y, z - 100));
	Vertices.Add(FVector(100 + offset_x, -100 + offset_y, z + 100));
	Vertices.Add(FVector(100 + offset_x, 100 + offset_y, z + 100));
	Vertices.Add(FVector(100 + offset_x, -100 + offset_y, z - 100));

	Vertices.Add(FVector(-100 + offset_x, 100 + offset_y, z + 100));
	Vertices.Add(FVector(100 + offset_x, 100 + offset_y, z - 100));
	Vertices.Add(FVector(-100 + offset_x, 100 + offset_y, z - 100));
	Vertices.Add(FVector(100 + offset_x, 100 + offset_y, z + 100));
	Vertices.Add(FVector(-100 + offset_x, 100 + offset_y, z + 100));
	Vertices.Add(FVector(100 + offset_x, 100 + offset_y, z - 100));

	Vertices.Add(FVector(100 + offset_x, -100 + offset_y, z + 100));
	Vertices.Add(FVector(100 + offset_x, -100 + offset_y, z - 100));
	Vertices.Add(FVector(-100 + offset_x, -100 + offset_y, z - 100));
	Vertices.Add(FVector(-100 + offset_x, -100 + offset_y, z + 100));
	Vertices.Add(FVector(100 + offset_x, -100 + offset_y, z + 100));
	Vertices.Add(FVector(-100 + offset_x, -100 + offset_y, z - 100));

	Triangles.Add(29);
	Triangles.Add(28);
	Triangles.Add(27);
	Triangles.Add(26);
	Triangles.Add(25);
	Triangles.Add(24);

	Triangles.Add(23);
	Triangles.Add(22);
	Triangles.Add(21);
	Triangles.Add(20);
	Triangles.Add(19);
	Triangles.Add(18);

	Triangles.Add(17);
	Triangles.Add(16);
	Triangles.Add(15);
	Triangles.Add(14);
	Triangles.Add(13);
	Triangles.Add(12);

	Triangles.Add(11);
	Triangles.Add(10);
	Triangles.Add(9);
	Triangles.Add(8);
	Triangles.Add(7);
	Triangles.Add(6);

	Triangles.Add(5);
	Triangles.Add(4);
	Triangles.Add(3);
	Triangles.Add(2);
	Triangles.Add(1);
	Triangles.Add(0);
	/*
	for (int k = triangle_offset; k < triangle_offset + 2; k++)
	{
		Triangles.Add(k);
	}
	*/
	Refresh();
}
void AVoxelWorld::EraseVoxel(int x, int y)
{

}
void AVoxelWorld::Refresh(){
	ProceduralMesh->CreateMeshSection_LinearColor(0, Vertices, Triangles, TArray<FVector>(), TArray<FVector2D>(), TArray<FLinearColor>(), TArray<FProcMeshTangent>(), true);
	ProceduralMesh->SetMaterial(0, MATS.Top());
	ProceduralMesh->CreateMeshSection_LinearColor(0, Vertices, Triangles, TArray<FVector>(), TArray<FVector2D>(), TArray<FLinearColor>(), TArray<FProcMeshTangent>(), true);
	// Update mesh collision if necessary
	ProceduralMesh->ContainsPhysicsTriMeshData(true);
}
// Called when the game starts or when spawned
void AVoxelWorld::BeginPlay()
{
	Super::BeginPlay();
	CreateVoxel();
}

// Called every frame
void AVoxelWorld::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

