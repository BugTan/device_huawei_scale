# Audio
PRODUCT_PROPERTY_OVERRIDES += \
    audio.deep_buffer.media=true \
    audio.offload.buffer.size.kb=64 \
    audio.offload.gapless.enabled=true \
    audio.offload.min.duration.secs=30 \
    audio.offload.pcm.16bit.enable=false \
    audio.offload.pcm.24bit.enable=true \
    audio.offload.video=true \
    av.streaming.offload.enable=true \
    media.aac_51_output_enabled=true \
    persist.audio.fluence.speaker=true \
    persist.audio.fluence.voicecall=true \
    persist.audio.fluence.voicerec=false \
    ro.qc.sdk.audio.fluencetype=none \
    use.voice.path.for.pcm.voip=true

# Bluetooth
PRODUCT_PROPERTY_OVERRIDES += \
    qcom.bluetooth.soc=smd \
    ro.bluetooth.dun=true \
    ro.bluetooth.hfp.ver=1.7 \
    ro.bluetooth.sap=true \
    ro.qualcomm.bt.hci_transport=smd

# Camera
PRODUCT_PROPERTY_OVERRIDES += \
    camera2.portability.force_api=1 \
    media.stagefright.legacyencoder=true \
    media.stagefright.less-secure=true \
    persist.camera.hal.debug.mask=0

# Dalvik
PRODUCT_PROPERTY_OVERRIDES += \
    dalvik.vm.heapgrowthlimit=192m \
    dalvik.vm.heapmaxfree=8m \
    dalvik.vm.heapminfree=512k \
    dalvik.vm.heapsize=256m \
    dalvik.vm.heapstartsize=8m \
    dalvik.vm.heaptargetutilization=0.75

# Display
PRODUCT_PROPERTY_OVERRIDES += \
    debug.composition.type=dyn \
    debug.enable.sglscale=1 \
    debug.hwui.use_buffer_age=false \
    debug.mdpcomp.idletime=600 \
    persist.hwc.mdpcomp.enable=true \
    persist.hwc.ptor.enable=true \
    qemu.hw.mainkeys=0 \
    ro.sf.lcd_density=320

# DRM
PRODUCT_PROPERTY_OVERRIDES += \
    drm.service.enabled=true \
    vidc.enc.narrow.searchrange=1

# Perf
PRODUCT_PROPERTY_OVERRIDES += \
    ro.core_ctl_min_cpu=0 \
    ro.core_ctl_max_cpu=4 \
    ro.min_freq_0=800000 \
    ro.vendor.extension_library=libqti-perfd-client.so

# OpenGL ES
PRODUCT_PROPERTY_OVERRIDES += \
    ro.opengles.version=196608

# Radio
PRODUCT_PROPERTY_OVERRIDES += \
    persist.data.target=dpm1 \
    persist.data.qmi.adb_logmask=0 \
    persist.dsds.enabled=true \
    persist.radio.apm_sim_not_pwdn=1 \
    persist.radio.multisim.config=dsds \
    persist.radio.no_cons_man_roam=1 \
    persist.radio.sib16_support=1\
    ril.ecclist=000,08,100,101,102,110,112,118,119,120,122,911,999 \
    ril.ecclist1=000,08,100,101,102,110,112,118,119,120,122,911,999 \
    rild.libpath=/system/vendor/lib/libril-qc-qmi-1.so \
    ro.hwpp.cust_ons_bin=true \
    ro.telephony.call_ring.multiple=false \
    ro.telephony.ril.config=simactivation \
    ro.use_data_netmgrd=true

# SDcardFS
PRODUCT_PROPERTY_OVERRIDES += \
    ro.sys.sdcardfs=true

# Subsystem restart
PRODUCT_PROPERTY_OVERRIDES += \
    ro.am.reschedule_service=true \
    ro.config.max_starting_bg=8

# USB ID
PRODUCT_PROPERTY_OVERRIDES += \
    ro.usb.id.midi=90BA \
    ro.usb.id.midi_adb=90BB \
    ro.usb.id.mtp=1051 \
    ro.usb.id.mtp_adb=1052 \
    ro.usb.id.ptp=1083 \
    ro.usb.id.ptp_adb=1054 \
    ro.usb.id.ums=1037 \
    ro.usb.id.ums_adb=1038 \
    ro.usb.vid=12d1

# WiFi
PRODUCT_PROPERTY_OVERRIDES += \
    ro.disableWifiApFirmwareReload=true \
    wifi.interface=wlan0

# WiFi Display
PRODUCT_PROPERTY_OVERRIDES += \
    persist.debug.wfd.enable=1 \
    persist.sys.wfd.virtual=0
