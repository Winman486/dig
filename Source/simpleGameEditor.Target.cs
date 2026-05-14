// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class simpleGameEditorTarget : TargetRules
{
	public simpleGameEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		// Update from V5 to V6 per the error message
		DefaultBuildSettings = BuildSettingsVersion.V6;
		// Switching to Latest ensures compatibility with the current engine version
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("simpleGame");
	}
}