// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Puzzle_Multi_MasterEditorTarget : TargetRules
{
	public Puzzle_Multi_MasterEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("Puzzle_Multi_Master");
	}
}
