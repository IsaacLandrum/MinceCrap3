// Fill out your copyright notice in the Description page of Project Settings.

#include "Math/UnrealMathUtility.h"
#include "HexWorld.h"
// Sets default values
AHexWorld::AHexWorld()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ProceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = ProceduralMesh;
}
void AHexWorld::Refresh()
{
    ProceduralMesh->CreateMeshSection_LinearColor(0, Vertices, Triangles, TArray<FVector>(), TArray<FVector2D>(), TArray<FLinearColor>(), TArray<FProcMeshTangent>(), true);
    ProceduralMesh->SetMaterial(0, MATS.Top());
    //ProceduralMesh->CreateMeshSection_LinearColor(0, Vertices, Triangles, TArray<FVector>(), TArray<FVector2D>(), TArray<FLinearColor>(), TArray<FProcMeshTangent>(), true);
    // Update mesh collision if necessary
    ProceduralMesh->ContainsPhysicsTriMeshData(true);
}
void AHexWorld::EraseHex(int Row,int Col)
{
    for (int k = 0+18; k < 18+18; k++)
    {
        Triangles.Remove(k);
    }
    Refresh();
}
void AHexWorld::CreateHex() 
{
    bool inter = true;
    int offset = 0;
    int offset_x = 0;
    int triangle_offset = 0;
    for (int j = 0; j < size; j++)
    {
        offset += 154;
        if (inter)
        {
           
            offset_x = 0;
            inter = false;
        }
        else
        {
            inter = true;
            offset_x = 89;
       
        }
        for (int i = 0; i < size; i++)
        {
            //89 inter x, 154 inter y
            double z = 0;
             //   FMath::RandRange(0, 200);
            // Define vertices for a hex
            //1
            Vertices.Add(FVector(0 + offset_x, 100 + offset, z));
            Vertices.Add(FVector(86.6 + offset_x, 50 + offset, z));
            Vertices.Add(FVector(0 + offset_x, 0 + offset, z));
            //2
            Vertices.Add(FVector(86.6 + offset_x, 50 + offset, z));
            Vertices.Add(FVector(86.6 + offset_x, -50 + offset, z));
            Vertices.Add(FVector(0 + offset_x, 0 + offset, z));
            //3
            Vertices.Add(FVector(86.6 + offset_x, -50 + offset, z));
            Vertices.Add(FVector(0 + offset_x, -100 + offset, z));
            Vertices.Add(FVector(0 + offset_x, 0 + offset, z));
            //4
            Vertices.Add(FVector(0 + offset_x, -100 + offset, z));
            Vertices.Add(FVector(-86.6 + offset_x, -50 + offset, z));
            Vertices.Add(FVector(0 + offset_x, 0 + offset, z));
            //5
            Vertices.Add(FVector(-86.6 + offset_x, -50 + offset, z));
            Vertices.Add(FVector(-86.6 + offset_x, 50 + offset, z));
            Vertices.Add(FVector(0 + offset_x, 0 + offset, z));
            //6
            Vertices.Add(FVector(-86.6 + offset_x, 50 + offset, z));
            Vertices.Add(FVector(0 + offset_x, 100 + offset, z));
            Vertices.Add(FVector(0 + offset_x, 0 + offset, z));
            for (int k = triangle_offset; k < triangle_offset +18; k++)
            {
                Triangles.Add(k);
            }
            triangle_offset += 18;
            offset_x += 179;    
        }
    }
    Refresh();
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

