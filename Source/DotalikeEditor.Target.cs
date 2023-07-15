// Copyright 2023 Lautaro Javier Fernandez Pricco. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class DotalikeEditorTarget : TargetRules
{
	public DotalikeEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Dotalike" } );
	}
}
