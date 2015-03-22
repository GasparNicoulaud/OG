/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


using System;
using System.Runtime.InteropServices;

public class aiMaterial : IDisposable {
  private HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal aiMaterial(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(aiMaterial obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~aiMaterial() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          AssimpPINVOKE.delete_aiMaterial(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
    }
  }

    public aiColor4D Diffuse { get { var v = new aiColor4D(); return GetDiffuse(v)?v:DefaultDiffuse; } }
    public aiColor4D Specular { get { var v = new aiColor4D(); return GetSpecular(v)?v:DefaultSpecular; } }
    public aiColor4D Ambient { get { var v = new aiColor4D(); return GetAmbient(v)?v:DefaultAmbient; } }
    public aiColor4D Emissive { get { var v = new aiColor4D(); return GetEmissive(v)?v:DefaultEmissive; } }
    public float Opacity { get { float v = 0; return GetOpacity(ref v)?v:DefaultOpacity; } }
    public float ShininessStrength { get { float v = 0; return GetShininessStrength(ref v)?v:DefaultShininessStrength; } }    
    public aiShadingMode ShadingModel { get { int v = 0; return GetShadingModel(ref v)?((aiShadingMode)v):DefaultShadingModel; } }
    public aiTextureFlags TexFlagsDiffuse0 { get { int v = 0; return GetTexFlagsDiffuse0(ref v)?((aiTextureFlags)v):DefaultTexFlagsDiffuse0; } }
    public aiTextureMapMode MappingModeUDiffuse0 { get { int v = 0; return GetMappingModeUDiffuse0(ref v)?((aiTextureMapMode)v):DefaultMappingModeUDiffuse0; } }
    public aiTextureMapMode MappingModeVDiffuse0 { get { int v = 0; return GetMappingModeVDiffuse0(ref v)?((aiTextureMapMode)v):DefaultMappingModeVDiffuse0; } }
    public string TextureDiffuse0 { get { var v = new aiString(); return GetTextureDiffuse0(v)?v.ToString():DefaultTextureDiffuse; } }
    public bool TwoSided { get { int v = 0; return GetTwoSided(ref v)?(v!=0):DefaultTwoSided; } }
    
    // These values are returned if the value material property isn't set
    // Override these if you don't want to check for null
    public static aiColor4D DefaultDiffuse = new aiColor4D(1.0f, 1.0f, 1.0f, 1.0f);
    public static aiColor4D DefaultSpecular = new aiColor4D(1.0f, 1.0f, 1.0f, 1.0f);
    public static aiColor4D DefaultAmbient = new aiColor4D(0.0f, 0.0f, 0.0f, 1.0f);
    public static aiColor4D DefaultEmissive = new aiColor4D(0.0f, 0.0f, 0.0f, 1.0f);
    public static float DefaultShininessStrength = 1.0f;
    public static float DefaultOpacity = 1.0f;
    public static aiShadingMode DefaultShadingModel = (aiShadingMode)0;
    public static aiTextureFlags DefaultTexFlagsDiffuse0 = (aiTextureFlags)0;
    public static aiTextureMapMode DefaultMappingModeUDiffuse0 = aiTextureMapMode.aiTextureMapMode_Wrap;
    public static aiTextureMapMode DefaultMappingModeVDiffuse0 = aiTextureMapMode.aiTextureMapMode_Wrap;
    public static string DefaultTextureDiffuse = null;
    public static bool DefaultTwoSided = false;

  public aiMaterial() : this(AssimpPINVOKE.new_aiMaterial(), true) {
  }

  public uint GetTextureCount(aiTextureType type) {
    uint ret = AssimpPINVOKE.aiMaterial_GetTextureCount(swigCPtr, (int)type);
    return ret;
  }

  public aiReturn AddBinaryProperty(SWIGTYPE_p_void pInput, uint pSizeInBytes, string pKey, uint type, uint index, aiPropertyTypeInfo pType) {
    aiReturn ret = (aiReturn)AssimpPINVOKE.aiMaterial_AddBinaryProperty(swigCPtr, SWIGTYPE_p_void.getCPtr(pInput), pSizeInBytes, pKey, type, index, (int)pType);
    return ret;
  }

  public aiReturn AddProperty(aiString pInput, string pKey, uint type, uint index) {
    aiReturn ret = (aiReturn)AssimpPINVOKE.aiMaterial_AddProperty__SWIG_0(swigCPtr, aiString.getCPtr(pInput), pKey, type, index);
    return ret;
  }

  public aiReturn AddProperty(aiString pInput, string pKey, uint type) {
    aiReturn ret = (aiReturn)AssimpPINVOKE.aiMaterial_AddProperty__SWIG_1(swigCPtr, aiString.getCPtr(pInput), pKey, type);
    return ret;
  }

  public aiReturn AddProperty(aiString pInput, string pKey) {
    aiReturn ret = (aiReturn)AssimpPINVOKE.aiMaterial_AddProperty__SWIG_2(swigCPtr, aiString.getCPtr(pInput), pKey);
    return ret;
  }

  public aiReturn RemoveProperty(string pKey, uint type, uint index) {
    aiReturn ret = (aiReturn)AssimpPINVOKE.aiMaterial_RemoveProperty__SWIG_0(swigCPtr, pKey, type, index);
    return ret;
  }

  public aiReturn RemoveProperty(string pKey, uint type) {
    aiReturn ret = (aiReturn)AssimpPINVOKE.aiMaterial_RemoveProperty__SWIG_1(swigCPtr, pKey, type);
    return ret;
  }

  public aiReturn RemoveProperty(string pKey) {
    aiReturn ret = (aiReturn)AssimpPINVOKE.aiMaterial_RemoveProperty__SWIG_2(swigCPtr, pKey);
    return ret;
  }

  public void Clear() {
    AssimpPINVOKE.aiMaterial_Clear(swigCPtr);
  }

  public static void CopyPropertyList(aiMaterial pcDest, aiMaterial pcSrc) {
    AssimpPINVOKE.aiMaterial_CopyPropertyList(aiMaterial.getCPtr(pcDest), aiMaterial.getCPtr(pcSrc));
  }

  public bool GetDiffuse(aiColor4D INOUT) {
    bool ret = AssimpPINVOKE.aiMaterial_GetDiffuse(swigCPtr, aiColor4D.getCPtr(INOUT));
    return ret;
  }

  public bool GetSpecular(aiColor4D INOUT) {
    bool ret = AssimpPINVOKE.aiMaterial_GetSpecular(swigCPtr, aiColor4D.getCPtr(INOUT));
    return ret;
  }

  public bool GetAmbient(aiColor4D INOUT) {
    bool ret = AssimpPINVOKE.aiMaterial_GetAmbient(swigCPtr, aiColor4D.getCPtr(INOUT));
    return ret;
  }

  public bool GetEmissive(aiColor4D INOUT) {
    bool ret = AssimpPINVOKE.aiMaterial_GetEmissive(swigCPtr, aiColor4D.getCPtr(INOUT));
    return ret;
  }

  public bool GetOpacity(ref float INOUT) {
    bool ret = AssimpPINVOKE.aiMaterial_GetOpacity(swigCPtr, ref INOUT);
    return ret;
  }

  public bool GetShininessStrength(ref float INOUT) {
    bool ret = AssimpPINVOKE.aiMaterial_GetShininessStrength(swigCPtr, ref INOUT);
    return ret;
  }

  public bool GetShadingModel(ref int INOUT) {
    bool ret = AssimpPINVOKE.aiMaterial_GetShadingModel(swigCPtr, ref INOUT);
    return ret;
  }

  public bool GetTexFlagsDiffuse0(ref int INOUT) {
    bool ret = AssimpPINVOKE.aiMaterial_GetTexFlagsDiffuse0(swigCPtr, ref INOUT);
    return ret;
  }

  public bool GetMappingModeUDiffuse0(ref int INOUT) {
    bool ret = AssimpPINVOKE.aiMaterial_GetMappingModeUDiffuse0(swigCPtr, ref INOUT);
    return ret;
  }

  public bool GetMappingModeVDiffuse0(ref int INOUT) {
    bool ret = AssimpPINVOKE.aiMaterial_GetMappingModeVDiffuse0(swigCPtr, ref INOUT);
    return ret;
  }

  public bool GetTextureDiffuse0(aiString INOUT) {
    bool ret = AssimpPINVOKE.aiMaterial_GetTextureDiffuse0(swigCPtr, aiString.getCPtr(INOUT));
    return ret;
  }

  public bool GetTextureSpecular0(aiString INOUT) {
    bool ret = AssimpPINVOKE.aiMaterial_GetTextureSpecular0(swigCPtr, aiString.getCPtr(INOUT));
    return ret;
  }

  public bool GetTextureOpacity0(aiString INOUT) {
    bool ret = AssimpPINVOKE.aiMaterial_GetTextureOpacity0(swigCPtr, aiString.getCPtr(INOUT));
    return ret;
  }

  public bool GetTextureAmbient0(aiString INOUT) {
    bool ret = AssimpPINVOKE.aiMaterial_GetTextureAmbient0(swigCPtr, aiString.getCPtr(INOUT));
    return ret;
  }

  public bool GetTextureEmissive0(aiString INOUT) {
    bool ret = AssimpPINVOKE.aiMaterial_GetTextureEmissive0(swigCPtr, aiString.getCPtr(INOUT));
    return ret;
  }

  public bool GetTextureShininess0(aiString INOUT) {
    bool ret = AssimpPINVOKE.aiMaterial_GetTextureShininess0(swigCPtr, aiString.getCPtr(INOUT));
    return ret;
  }

  public bool GetTextureLightmap0(aiString INOUT) {
    bool ret = AssimpPINVOKE.aiMaterial_GetTextureLightmap0(swigCPtr, aiString.getCPtr(INOUT));
    return ret;
  }

  public bool GetTextureNormals0(aiString INOUT) {
    bool ret = AssimpPINVOKE.aiMaterial_GetTextureNormals0(swigCPtr, aiString.getCPtr(INOUT));
    return ret;
  }

  public bool GetTextureHeight0(aiString INOUT) {
    bool ret = AssimpPINVOKE.aiMaterial_GetTextureHeight0(swigCPtr, aiString.getCPtr(INOUT));
    return ret;
  }

  public bool GetGlobalBackgroundImage(aiString INOUT) {
    bool ret = AssimpPINVOKE.aiMaterial_GetGlobalBackgroundImage(swigCPtr, aiString.getCPtr(INOUT));
    return ret;
  }

  public bool GetTwoSided(ref int INOUT) {
    bool ret = AssimpPINVOKE.aiMaterial_GetTwoSided(swigCPtr, ref INOUT);
    return ret;
  }

}
