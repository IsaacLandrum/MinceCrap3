// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MinceCrap3 : ModuleRules
{
	public MinceCrap3(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "ProceduralMeshComponent" });
	}
}
