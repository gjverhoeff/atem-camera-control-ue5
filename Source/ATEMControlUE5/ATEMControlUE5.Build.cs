

using UnrealBuildTool;

public class ATEMControlUE5 : ModuleRules
{
	public ATEMControlUE5(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"WebSockets",
				"Json",
				"JsonUtilities"
			}
		);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Engine",
				"Slate",
				"SlateCore"
			}
		);

		PublicDefinitions.Add("WITH_WEBSOCKETS=1");
	}
}
