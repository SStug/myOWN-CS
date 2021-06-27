function setWaterColor(command, red, green, blue)
  setWaterColor(red, green, blue)
  end
addCommandHandler("setwc", setWaterColor)
function resetWaterColor()
  resetWaterColor()
  end
addCommandHandler("resetwc", resetWaterColor)
addEventHandler("onClientResourceStop", getRootElement(), setWaterColor)
