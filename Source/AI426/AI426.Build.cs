// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AI426 : ModuleRules
{
	public AI426(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "GameplayTasks" });//GameplayTaks is needed for BTTaskNode
	}
}
