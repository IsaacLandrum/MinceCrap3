// Fill out your copyright notice in the Description page of Project Settings.


#include "HexWorld.h"
// Sets default values
AHexWorld::AHexWorld()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ProceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = ProceduralMesh;
}
void AHexWorld::CreateHex() 
{
    int offset = 0;
    int offset_x = 0;
    int triangle_offset = 0;
    for (int j = 0; j < size; j++)
    {
        offset = 0;
        for (int i = 0; i < size; i++)
        {
            // Define vertices for a hex
             //1
            Vertices.Add(FVector(0 + offset_x, 0 + offset, 0));
            Vertices.Add(FVector(0 + offset_x, 100 + offset, 0));
            Vertices.Add(FVector(50 + offset_x, 86.6 + offset, 0));
          
            for (int k = triangle_offset; k < triangle_offset +3; k++)
            {
                Triangles.Add(k);
                //Triangles.Add(1);
                //Triangles.Add(2);
            }
            triangle_offset += 3;
            offset += 200;

        }
        offset_x += 200;
    }
    ProceduralMesh->CreateMeshSection_LinearColor(0, Vertices, Triangles, TArray<FVector>(), TArray<FVector2D>(), TArray<FLinearColor>(), TArray<FProcMeshTangent>(), true);

    // Update mesh collision if necessary
    ProceduralMesh->ContainsPhysicsTriMeshData(true);
}
// Called when the game starts or when spawned
void AHexWorld::BeginPlay()
{
	Super::BeginPlay();
    CreateHex();
}

// Called every frame
void AHexWorld::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

