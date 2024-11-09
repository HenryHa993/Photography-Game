// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TDA_TheGame : ModuleRules
{
	public TDA_TheGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "Inkpot", "UMG", "Slate", "SlateCore" });
	}
}
