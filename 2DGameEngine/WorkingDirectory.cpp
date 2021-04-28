#include "WorkingDirectory.h"

WorkingDirectory::WorkingDirectory()
{
	path = "./"; 

#ifdef MACOS
	//Change the default working directory to that of the XCode resource path
	// on MacOS. 
	CFBundleRef mainBundle = CFBundleGetMainBundle();
	CFURLRef resourcesURL =
		CFBundleCopyResourcesDirectoryURL(mainBundle);
	char path[PATH_MAX];
	if (CFURLGetFileSystemRepresentation(
		resourcesURL, TRUE, (UInt8*)path, PATH_MAX))
	{
		CFRelease(resourcesURL);
		chdir(path);
	}
#endif

}
