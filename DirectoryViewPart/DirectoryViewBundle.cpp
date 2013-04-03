#include "StdAfx.h"
#include "DirectoryViewBundle.h"

DirectoryViewBundle::DirectoryViewBundle()
{

}

DirectoryViewBundle::~DirectoryViewBundle()
{

}

void DirectoryViewBundle::start( IBundleContext* context )
{

}

void DirectoryViewBundle::stop( IBundleContext* context )
{

}

BundleConfigPtr DirectoryViewBundle::bundConfiguration()
{
	BundleConfigPtr bundConfig(new BundleConfiguration(
		"view", "DirectoryViewBundle", "DirectoryViewPart.dll"));
	return bundConfig;
}