/**
 * @file <argos3/plugins/robots/eye-bot/simulator/eyebot_entity.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef EYEBOT_ENTITY_H
#define EYEBOT_ENTITY_H

namespace argos {
   class CControllableEntity;
   class CEmbodiedEntity;
   class CEyeBotEntity;
   class CLEDEquippedEntity;
   class CLightSensorEquippedEntity;
   class CPerspectiveCameraEquippedEntity;
   class CProximitySensorEquippedEntity;
   class CQuadRotorEntity;
   class CRABEquippedEntity;
   class CBatteryEquippedEntity;
}

#include <argos3/core/simulator/entity/composable_entity.h>

namespace argos {

   class CEyeBotEntity : public CComposableEntity {

   public:

      ENABLE_VTABLE();

   public:
      static const CDegrees PERSPECTIVE_CAMERA_DEFAULT_APERTURE;
      static const Real PERSPECTIVE_CAMERA_DEFAULT_FOCAL_LENGTH;
      static const Real PERSPECTIVE_CAMERA_DEFAULT_RANGE;
      static const UInt32 PERSPECTIVE_CAMERA_DEFAULT_IMAGE_HEIGHT;
      static const UInt32 PERSPECTIVE_CAMERA_DEFAULT_IMAGE_WIDTH;

      static const Real RAB_DEFAULT_RANGE;
      static const size_t RAB_DEFAULT_MSG_SIZE;
      static const Real RAB_DEFAULT_ELEVATION;
      static const CQuaternion RAB_DEFAULT_ROT_OFFSET;

      CEyeBotEntity();

      CEyeBotEntity(const std::string& str_id,
                    const std::string& str_controller_id,
                    const CVector3& c_position = CVector3(),
                    const CQuaternion& c_orientation = CQuaternion(),
                    Real f_rab_range = RAB_DEFAULT_RANGE,
                    size_t un_rab_data_size = RAB_DEFAULT_MSG_SIZE,
                    const std::string& str_bat_model = "",
                    const CRadians& c_perspcam_aperture = ToRadians(PERSPECTIVE_CAMERA_DEFAULT_APERTURE),
                    Real f_perspcam_focal_length = PERSPECTIVE_CAMERA_DEFAULT_FOCAL_LENGTH,
                    Real f_perspcam_range = PERSPECTIVE_CAMERA_DEFAULT_RANGE);

      virtual void Init(TConfigurationNode& t_tree);
      virtual void Reset();

      virtual void UpdateComponents();

      inline CControllableEntity& GetControllableEntity() {
         return *m_pcControllableEntity;
      }

      inline CEmbodiedEntity& GetEmbodiedEntity() {
         return *m_pcEmbodiedEntity;
      }

      inline CLEDEquippedEntity& GetLEDEquippedEntity() {
         return *m_pcLEDEquippedEntity;
      }

      inline CLightSensorEquippedEntity& GetLightSensorEquippedEntity() {
         return *m_pcLightSensorEquippedEntity;
      }

      inline CProximitySensorEquippedEntity& GetProximitySensorEquippedEntity() {
         return *m_pcProximitySensorEquippedEntity;
      }

      inline CQuadRotorEntity& GetQuadRotorEntity() {
         return *m_pcQuadRotorEntity;
      }

      inline CRABEquippedEntity& GetRABEquippedEntity() {
         return *m_pcRABEquippedEntity;
      }

      inline CBatteryEquippedEntity& GetBatterySensorEquippedEntity() {
          return *m_pcBatteryEquippedEntity;
      }

      virtual std::string GetTypeDescription() const {
         return "eye-bot";
      }

   private:

      CControllableEntity*              m_pcControllableEntity;
      CEmbodiedEntity*                  m_pcEmbodiedEntity;
      CLEDEquippedEntity*               m_pcLEDEquippedEntity;
      CLightSensorEquippedEntity*       m_pcLightSensorEquippedEntity;
      CPerspectiveCameraEquippedEntity* m_pcPerspectiveCameraEquippedEntity;
      CProximitySensorEquippedEntity*   m_pcProximitySensorEquippedEntity;
      CQuadRotorEntity*                 m_pcQuadRotorEntity;
      CRABEquippedEntity*               m_pcRABEquippedEntity;
      CBatteryEquippedEntity*           m_pcBatteryEquippedEntity;
   };

}

#endif
