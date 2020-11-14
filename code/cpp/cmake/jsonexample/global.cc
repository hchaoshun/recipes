//
// Created by 黄朝顺 on 2020-07-09.
//

#include "global.h"

bool LabelProfileDict::load() {
  std::string file_path = fullFileName(file_name);
  std::ifstream ifs(file_path);
  if (!ifs.is_open())
  {
    std::cerr << " open dict " << file_path << " failed";
    return false;
  }
  std::string data((std::istreambuf_iterator<char>(ifs)),
                   std::istreambuf_iterator<char>());
  std::cout << "data: " << data << std::endl;
  nlohmann::json j;
  try
  {
    j = nlohmann::json::parse(data);
  }
  catch (const std::exception& e)
  {
    std::cerr << "parse json from " << file_path << " failed, err=" << e.what();
    return false;
  }
  level_mapping_.clear();
  labels_.clear();
  auto succ = parseLevelMapping(j) && parseLabels(j);
  std::string status = succ ? " success " : " failed ";
  return succ;
}

bool LabelProfileDict::parseLevelMapping(const nlohmann::json &j) {
  if (!j.is_object()) {
    std::cerr << "json is not object, file=" << file_name;
    return false;
  }
  if (j.find("level") == j.end()) {
    std::cerr << "not find level in json: " << file_name;
    return false;
  }
  const auto& level = j["level"];
  if (!level.is_object()) {
    std::cerr << "level is not json object: " << file_name;
    return false;
  }
  for (const auto& [level_type, level_min_max] : level.items()) {
    std::pair<double, double> p;
    if (level_min_max.find("min") == level_min_max.end() ||
        !level_min_max["min"].is_number())
    {
      std::cerr << "not found min in level or min is not number: " << file_name;
      return false;
    }
    p.first = level_min_max["min"].get<double>();
    if (level_min_max.find("max") == level_min_max.end() ||
        !level_min_max["max"].is_number())
    {
      std::cerr << "not found max in level or max is not number: " << file_name;
      return false;
    }
    p.second = level_min_max["max"].get<double>();
    level_mapping_[level_type] = p;
  }
  return true;
}

bool LabelProfileDict::parseLabels(const nlohmann::json& j) {
  if (!j.is_object()) {
    std::cerr << "json is not object, file=" << file_name;
    return false;
  }
  if (j.find("labels") == j.end()) {
    std::cerr << "not find labels in json: " << file_name;
    return false;
  }
  const auto& labels = j["labels"];
  if (!labels.is_array())
  {
    std::cerr << "labels is not json array: " << file_name;
    return false;
  }
  for (const auto& label : labels) {
    if (!label.is_object())
    {
      std::cerr << "label is not json object: " << file_name;
      return false;
    }
    struct LabelItem label_item;
    if (label.find("label") == label.end() || !label["label"].is_string())
    {
      std::cerr << "not found label in labels or label is not string: " << file_name;
      return false;
    }
    label_item.label = label["label"].get<std::string>();
    if (label.find("playpv") == label.end() || !label["playpv"].is_number())
    {
      std::cerr << "not found playpv in labels or playpv is not number: " << file_name;
      return false;
    }
    label_item.playpv = label["playpv"].get<double>();
    if (label.find("playuvs_play_pv") == label.end() ||
        !label["playuvs_play_pv"].is_number())
    {
      std::cerr << "not found playuvs_play_pv in labels or "
                   "playuvs_play_pv is not number: " << file_name;
      return false;
    }
    label_item.playuvs_play_pvlabel = label["playuvs_play_pv"].get<double>();
    labels_.push_back(label_item);
  }
  return true;
}

