// maxon support, basic functions
void setQuestionMark()
{
  byte question_mark[8] = { 0x3C, 0xFF, 0xC3, 0x0E, 0x1C, 0x38, 0x00, 0x38 };

  for (uint8_t i = 0; i < sizeof(question_mark); i++)
  {
    lc.setRow(0, i, question_mark[i]);
  }
}

void setExclamatoryMark()
{
  byte exclamatory_mark[8] = { 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x18 };

  for (uint8_t i = 0; i < sizeof(exclamatory_mark); i++)
  {
    lc.setRow(0, i, exclamatory_mark[i]);
  }
}

void setError()
{
  byte error_mark[8] = { 0xC3, 0xE7, 0x7E, 0x3C, 0x3C, 0x7E, 0xE7, 0xC3 };

  for (uint8_t i = 0; i < sizeof(error_mark); i++)
  {
    lc.setRow(0, i, error_mark[i]);
  }
}

void setOk()
{
  byte ok_mark[8] = { 0x01, 0x03, 0x07, 0x0E, 0xDC, 0xF8, 0x70, 0x20 };

  for (uint8_t i = 0; i < sizeof(ok_mark); i++)
  {
    lc.setRow(0, i, ok_mark[i]);
  }
}