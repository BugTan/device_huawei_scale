# Copyright (C) 2016 The CyanogenMod Project
# Copyright (C) 2017 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Inherit from these products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/product_launched_with_l_mr1.mk)

# Inherit device configuration
$(call inherit-product, device/huawei/scale/device.mk)

# Inherit some common AIM stuff.
$(call inherit-product, vendor/aim/config/common_full_phone.mk)

# Boot animation
TARGET_SCREEN_WIDTH := 720

# Device identifications
PRODUCT_DEVICE := scale
PRODUCT_NAME := aim_scale
PRODUCT_BRAND := Huawei
PRODUCT_MANUFACTURER := HUAWEI

PRODUCT_GMS_CLIENTID_BASE := android-huawei

PRODUCT_SYSTEM_PROPERTY_BLACKLIST += \
    ro.product.model

# AIM OTA
ifeq ($(AIM_BUILDTYPE),OFFICIAL)
ifneq ($(RECOVERY_VARIANT),twrp)
PRODUCT_PROPERTY_OVERRIDES += \
    ro.ota.romname=AIMROM \
    ro.ota.version=$(shell date -u +"%Y%m%d") \
    ro.aim.maintainer=krasCGQ \
    ro.ota.manifest=https://raw.githubusercontent.com/AIMROM/AIM_OTA/N/scale.xml
endif
endif
