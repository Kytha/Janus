workspace "Janus"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (soltion directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Janus/vendor/GLFW/include"
IncludeDir["Glad"] = "Janus/vendor/Glad/include"
IncludeDir["ImGui"] = "Janus/vendor/ImGui"
IncludeDir["glm"] = "Janus/vendor/glm"
group "Dependencies"
	include "Janus/vendor/GLFW"
	include "Janus/vendor/Glad"
	include "Janus/vendor/ImGui"
group ""

project "Janus"
	location "Janus"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "jnpch.h"
	pchsource "Janus/src/jnpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src/",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
	}
	
	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"JN_PLATFORM_WINDOWS",
			"JN_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "JN_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "JN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "JN_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Janus/vendor/spdlog/include",
		"Janus/src",
		"%{IncludeDir.glm}",
		"Janus/vendor"
	}

	links {
		"Janus"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"JN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "JN_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "JN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "JN_DIST"
		runtime "Release"
		optimize "on"

		project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"
	
		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}
	
		includedirs
		{
			"Janus/vendor/spdlog/include",
			"Janus/src",
			"%{IncludeDir.glm}",
			"Janus/vendor"
		}
	
		links {
			"Janus"
		}
	
		filter "system:windows"
			systemversion "latest"
	
			defines
			{
				"JN_PLATFORM_WINDOWS"
			}
	
		filter "configurations:Debug"
			defines "JN_DEBUG"
			runtime "Debug"
			symbols "on"
	
		filter "configurations:Release"
			defines "JN_RELEASE"
			runtime "Release"
			optimize "on"
	
		filter "configurations:Dist"
			defines "JN_DIST"
			runtime "Release"
			optimize "on"