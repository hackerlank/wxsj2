#ifndef __FAIRYSKYBOXOBJECT_H__
#define __FAIRYSKYBOXOBJECT_H__

#include "FairyObject.h"

#include <OgreQuaternion.h>

namespace Fairy
{
    class ObjectFactory;

    class SkyBoxObject : public Object
    {
    protected:
        class Factory;

    public:
        SkyBoxObject(void);
        virtual ~SkyBoxObject();

        const Ogre::String& getType(void) const;
        const Ogre::String& getCategory(void) const;

        void createRenderInstance(System* system);
        void destroyRenderInstance(void);
        void updateRenderInstance(void);

        //////////////////////////////////////////////////////////////////////////

        static const Ogre::String msType;
        static const Ogre::String msCategory;

        static ObjectFactory* getFactory(void);
        //////////////////////////////////////////////////////////////////////////
   

    protected:
        Ogre::SceneManager* mSceneManager;

        void updateRenderInstanceImpl(void);

    public:     // Intend for direct access by property commands only, DO NOT access outside
        Ogre::String mMaterialName;
        Ogre::Real mDistance;
        bool mDrawFirst;
        Ogre::Quaternion mOrientation;

    };

}

#endif 
