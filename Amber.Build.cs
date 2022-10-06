// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Amber : ModuleRules
{
	public Amber(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
