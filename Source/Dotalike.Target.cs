// Copyright 2023 Lautaro Javier Fernandez Pricco. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class DotalikeTarget : TargetRules
{
	public DotalikeTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Dotalike" } );
	}
}
