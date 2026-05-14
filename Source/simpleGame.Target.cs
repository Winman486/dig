// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class simpleGameTarget : TargetRules
{
	public simpleGameTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		// Change V5 to V6 as requested by the error message
		DefaultBuildSettings = BuildSettingsVersion.V6; 
		
		// It is also recommended to set this to Latest for new engine versions
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest; 
		
		ExtraModuleNames.Add("simpleGame");
	}
}