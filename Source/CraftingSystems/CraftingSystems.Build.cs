// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CraftingSystems : ModuleRules
{
	public CraftingSystems(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
